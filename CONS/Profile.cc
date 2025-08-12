#include "Profile.hh"
#include "Base.hh"
#include "FASTA.hh"
#include <sstream>
#include <vector>

using Base = base::Base;

namespace profile {

Profile build_profile(std::istream &input) {
    std::string first_dna = fasta::next_dna_string(input);
    std::istringstream first_stream(first_dna);
    Profile prf(first_dna.size());
    prf += first_stream;
    prf += input;
    return prf;
}

Profile &Profile::operator+=(std::istream &input) {
    int i = 0;
    do {
        char c = input.peek();
        if (c == '>') {
            fasta::skip_label_line(input);
            i = 0; // new dna string found
        } else {
            std::optional<Base> b;
            if ((b = base::from_char(c))) {
                int start = static_cast<int>(*b) * n;
                matrix[start + i++]++;
            }
            input.get(); // move forward
        }
    } while (input);
    return *this;
}

std::string Profile::consensus() const {
    std::string dna(n, '\0');
    std::vector<int> cons(n, 0);

    for (size_t i = 0; i < base::N * n; i++) {
        if (cons[i % n] < matrix[i]) {
            cons[i % n] = matrix[i];
            dna[i % n] = to_char(base::All[i / n]);
        }
    }

    return dna;
}

std::ostream &operator<<(std::ostream &os, const Profile &p) {
    for (Base b : base::All) {
        os << b << ":";
        size_t start = static_cast<int>(b);
        for (size_t i = start * p.n; i < (start + 1) * p.n; i++) {
            os << " " << p.matrix[i];
        }
        os << '\n';
    }
    return os;
}

} // namespace profile
