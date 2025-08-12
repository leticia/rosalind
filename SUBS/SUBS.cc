#include <fstream>
#include <iostream>

bool is_motif(const std::string &dna, size_t start, const std::string &sub) {
  for (size_t i = start, j = 0; j < sub.length(); i++, j++) {
    if (dna[i] != sub[j])
      return false;
  }
  return true;
}

void find_motifs(const std::string &dna, const std::string &sub) {
  for (size_t i = 0; i < dna.length(); i++)
    if (is_motif(dna, i, sub))
      std::cout << i + 1 << " ";
}

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << "<file>" << std::endl;
    return 1;
  }
  std::ifstream file(argv[1]);
  std::string dna, sub;
  std::getline(file, dna);
  std::getline(file, sub);
  find_motifs(dna, sub);
  return 0;
}
