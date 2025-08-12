#include "Profile.hh"
#include <cassert>
#include <fstream>
#include <iostream>

using Profile = profile::Profile;

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <file>" << '\n';
        return 1;
    }

    std::ifstream file(argv[1]);
    assert(file && "can't open given file");

    Profile p = profile::build_profile(file);
    std::cout << p.consensus() << '\n' << p;
}
