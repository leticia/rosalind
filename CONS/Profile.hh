#pragma once

#include "Base.hh"
#include <iostream>

namespace profile {

class Profile {
  private:
    int n;
    int *matrix;

  public:
    explicit Profile(int n) : n{n}, matrix{new int[base::N * n]} {}
    ~Profile() { delete[] matrix; }

    Profile(Profile &&other) : n{other.n}, matrix{other.matrix} {
        other.n = 0;
        other.matrix = nullptr;
    }

    std::string consensus() const;

    Profile &operator+=(std::istream &);
    friend std::ostream &operator<<(std::ostream &, const Profile &);

    Profile(const Profile &) = delete;
    Profile &operator=(const Profile &) = delete;
    Profile &operator=(Profile &&) = delete;
};

Profile build_profile(std::istream &);

} // namespace profile
