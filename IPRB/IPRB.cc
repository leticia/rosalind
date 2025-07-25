#include <iostream>

inline double pr(int n, int m) { return static_cast<double>(n) / m; }

// k: homozygous dominant  (YY)
// m: heterozygous         (Yy)
// n: homozygous recessive (yy)
double dominantProb(int k, int m, int n) {
  int t = k + m + n;
  // TODO...
}

int main(int argc, char **argv) {
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0] << "k m n" << std::endl;
    return 1;
  }

  int k = std::stoi(argv[1]);
  int m = std::stoi(argv[2]);
  int n = std::stoi(argv[3]);

  std::cout << std::fixed << dominantProb(k, m, n) << std::endl;

  return 0;
}
