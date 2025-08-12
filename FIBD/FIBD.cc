#include <iostream>
#include <numeric>
#include <vector>

size_t fib(int n, int m) {
  std::vector<size_t> rabbits(m); // one slot per month of life
  rabbits[0] = 1; // start with 1 yong pair

  // Steps:
  //   1. all adults [1..) produce offsprings
  //   2. all rabbits age by 1 month (rotate right)
  //   3. offsprings are placed at first month (0)
  for (int month = 1; month < n; month++) {
    size_t offspring = std::accumulate(rabbits.begin() + 1, rabbits.end(), 0ULL);
    std::rotate(rabbits.rbegin(), rabbits.rbegin() + 1, rabbits.rend());
    rabbits[0] = offspring;
  }

  return std::accumulate(rabbits.begin(), rabbits.end(), 0ULL);
}

int main(int argc, char** argv) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <n> <m>" << std::endl;
    return 1;
  }

  int n = std::atoi(argv[1]);
  int m = std::atoi(argv[2]);
  std::cout << fib(n, m) << std::endl;
}
