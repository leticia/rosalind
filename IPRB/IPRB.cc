#include <iostream>

// returns the propability of taking an element of group n in the population m.
inline double pr(int n, int m) { return static_cast<double>(n) / m; }

// k: homozygous dominant  (YY)
// m: heterozygous         (Yy)
// n: homozygous recessive (yy)
double dominantPr(int k, int m, int n) {
  int t = k + m + n;
  double p = .0;
  p += pr(k, t) * pr(k - 1, t - 1);       // pair: k & k
  p += pr(k, t) * pr(m, t - 1);           // pair: k & m
  p += pr(k, t) * pr(n, t - 1);           // pair: k & n
  p += pr(m, t) * pr(m - 1, t - 1) * .75; // pair: m & m
  p += pr(m, t) * pr(k, t - 1);           // pair: m & k
  p += pr(m, t) * pr(n, t - 1) * .5;      // pair: m & n
  p += pr(n, t) * pr(k, t - 1);           // pair: n & k
  p += pr(n, t) * pr(m, t - 1) * .5;      // pair: n & m
  return p;
}

int main(int argc, char **argv) {
  if (argc < 4) {
    std::cerr << "Usage: " << argv[0] << "k m n" << std::endl;
    return 1;
  }

  int k = std::stoi(argv[1]);
  int m = std::stoi(argv[2]);
  int n = std::stoi(argv[3]);

  std::cout << std::fixed << dominantPr(k, m, n) << std::endl;

  return 0;
}
