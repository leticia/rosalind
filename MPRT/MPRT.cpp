#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>

#include <curl/curl.h>

const std::regex n_glycosylation("N[^P][ST][^P]");

// CURL lib hook: write the HTTP content into a std::string buffer. This looks
// ugly because it's a C library callback.
size_t write_callback(void* contents, size_t size, size_t nmemb, void* userp) {
  ((std::string*)userp)->append((char*)contents, size * nmemb);
  return size * nmemb;
}

// Uses CURL lib to download the fasta file. Returns the protein sequence (no
// first line/metada header).
std::string download_fasta(const std::string& id) {
  std::string url = "https://rest.uniprot.org/uniprotkb/";

  // The ID is just the first part (nothing after the '_')
  auto underscore = id.find('_');
  if (underscore != std::string::npos)
    url += id.substr(0, underscore);
  else
    url += id;

  url += ".fasta";

  CURL* curl = curl_easy_init();
  if (!curl) {
    std::cerr << "Failed to init curl" << std::endl;
    std::exit(1);
  }

  std::string buffer;
  curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
  CURLcode res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);

  if (res != CURLE_OK) {
    std::cerr << "Download failed: " << curl_easy_strerror(res) << std::endl;
    std::exit(1);
  }

  if (buffer.find("Error") != std::string::npos) {
    std::cerr << "Request failed (" << id << "): " << buffer << std::endl;
    std::exit(1);
  }

  // Locates where the protein sequence starts (after first \n).
  size_t start = buffer.find('\n');
  if (start == std::string::npos) {
    std::cerr << "Invalid fasta string ("<< id << "): " << buffer << std::endl;
    std::exit(1);
  }

  // Prune the string living only the protein sequence in.
  std::erase(buffer, '\n');
  return buffer.substr(start);
}

void print_motifs(const std::string& id, const std::string& fasta) {
  bool first = true;
  std::smatch match;

  for (size_t i = 0;
       std::regex_search(fasta.begin() + i, fasta.end(),
                         match, n_glycosylation); ) {
    if (first) {
      std::cout << id << std::endl;
      first = false;
    }
    i += match.position(0) + 1;
    std::cout << i << " ";
  }

  if (!first) // found something?
    std::cout << std::endl;
}

int main(int argc, char** argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <file>" << std::endl;
    return 1;
  }

  curl_global_init(CURL_GLOBAL_DEFAULT);
  std::ifstream file(argv[1]);

  for (std::string id; std::getline(file, id);) {
    std::string fasta = download_fasta(id);
    print_motifs(id, fasta);
  }

  curl_global_cleanup();
}
