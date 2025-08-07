#include <algorithm>
#include <fstream>
#include <iostream>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

using namespace std;

vector<string> load_fasta(string path) {
  ifstream file(path);
  vector<string> strs;
  string dna, line;

  while (getline(file, line)) {
    if (line[0] == '>') {
      if (!dna.empty())
        strs.emplace_back(std::move(dna));
    } else {
      dna += line;
    }
  }

  strs.emplace_back(std::move(dna));
  return strs;
}

optional<string> find_largest_motif(vector<string> strs) {
  // Find the smallest string: there can't be a substring larger than this in
  // any other element in the given vector.
  const string &min = *min_element(strs.begin(), strs.end());

  // Steps:
  //   - 2 fors to get all substrings from `min` string in decreasing size;
  //   - take a substring of size `len` of the `min` string at `start`;
  //   - check of all *other* strings (begin()+1) contain the current substring.
  //
  // Retruning the first finding ensures we're returning one of the possible
  // largest substrings.
  for (size_t len = min.length(); len > 0; --len) {
    for (size_t start = 0; start <= min.length() - len; ++start) {
      string_view substr(min.c_str() + start, len); // zero-copy
      if (all_of(strs.begin() + 1, strs.end(), [&](const string &dna) {
            return dna.find(substr) != string_view::npos;
          }))
        return min.substr(start, len);
    }
  }

  return nullopt;
}

int main(int argc, char **argv) {
  if (argc != 2) {
    cerr << "Usage: " << argv[0] << " <file>" << endl;
    return 1;
  }

  auto strs = load_fasta(argv[1]);
  auto motif = find_largest_motif(strs);
  cout << *motif << endl;
}
