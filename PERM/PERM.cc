#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int factorial(int n) {
    int res = 1;
    for (int i = 1; i <= n; i++)
        res *= i;
    return res;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <n>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);
    std::cout << factorial(n) << '\n'; // permutations: n!

    std::vector<int> nums(n);
    std::iota(nums.begin(), nums.end(), 1);
    auto out = std::ostream_iterator<int>(std::cout, " ");

    do {
        std::copy(nums.begin(), nums.end(), out);
        std::cout << '\n';
    } while (std::next_permutation(nums.begin(), nums.end()));
}
