#include <array>
#include <fstream>
#include <ios>
#include <iostream>

// Codifies weights as a constant lookup table. Zero values are represent
// invalid positions. Trades a bit of space for quick weight lookups.
constexpr std::array<double, 25> table{{
    71.03711,  // 'A'
    0,         // 'B' (invalid)
    103.00919, // 'C'
    115.02694, // 'D'
    129.04259, // 'E'
    147.06841, // 'F'
    57.02146,  // 'G'
    137.05891, // 'H'
    113.08406, // 'I'
    0,         // 'J' (invalid)
    128.09496, // 'K'
    113.08406, // 'L'
    131.04049, // 'M'
    114.04293, // 'N'
    0,         // 'O' (invalid)
    97.05276,  // 'P'
    128.05858, // 'Q'
    156.10111, // 'R'
    87.03203,  // 'S'
    101.04768, // 'T'
    0,         // 'U' (invalid)
    99.06841,  // 'V'
    186.07931, // 'W'
    0,         // 'X' (invalid)
    163.06333, // 'Y'
}};

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <file>" << std::endl;
        return 1;
    }

    std::ifstream file(argv[1]);
    double weight = 0;

    char c;
    while (file >> c) {
        weight += table[c - 'A'];
    }

    std::cout << std::fixed << weight << std::endl;
}
