#include <fstream>
#include <iostream>
#include <unordered_map>

std::unordered_map<std::string, char> condon_table{
    {"UUU", 'F'}, {"CUU", 'L'}, {"AUU", 'I'}, {"GUU", 'V'}, {"UUC", 'F'},
    {"CUC", 'L'}, {"AUC", 'I'}, {"GUC", 'V'}, {"UUA", 'L'}, {"CUA", 'L'},
    {"AUA", 'I'}, {"GUA", 'V'}, {"UUG", 'L'}, {"CUG", 'L'}, {"AUG", 'M'},
    {"GUG", 'V'}, {"UCU", 'S'}, {"CCU", 'P'}, {"ACU", 'T'}, {"GCU", 'A'},
    {"UCC", 'S'}, {"CCC", 'P'}, {"ACC", 'T'}, {"GCC", 'A'}, {"UCA", 'S'},
    {"CCA", 'P'}, {"ACA", 'T'}, {"GCA", 'A'}, {"UCG", 'S'}, {"CCG", 'P'},
    {"ACG", 'T'}, {"GCG", 'A'}, {"UAU", 'Y'}, {"CAU", 'H'}, {"AAU", 'N'},
    {"GAU", 'D'}, {"UAC", 'Y'}, {"CAC", 'H'}, {"AAC", 'N'}, {"GAC", 'D'},
    {"CAA", 'Q'}, {"AAA", 'K'}, {"GAA", 'E'}, {"CAG", 'Q'}, {"AAG", 'K'},
    {"GAG", 'E'}, {"UGU", 'C'}, {"CGU", 'R'}, {"AGU", 'S'}, {"GGU", 'G'},
    {"UGC", 'C'}, {"CGC", 'R'}, {"AGC", 'S'}, {"GGC", 'G'}, {"CGA", 'R'},
    {"AGA", 'R'}, {"GGA", 'G'}, {"UGG", 'W'}, {"CGG", 'R'}, {"AGG", 'R'},
    {"GGG", 'G'},
};

int main(int argc, char **argv) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << "<file>" << std::endl;
    return 1;
  }

  std::ifstream file(argv[1]);
  char condon[4]; // 3 chars + \0 terminator (C-string)

  while (file >> condon) {
    if (auto search = condon_table.find(condon); search != condon_table.end()) {
      std::cout << search->second; // first == key, second == value
    } else {
      break;
    }
  }

  std::cout << std::endl;
}
