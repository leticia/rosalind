#include "Base.hh"

namespace base {

std::optional<Base> from_char(char c) {
    switch (c) {
    case 'A':
        return Base::A;
    case 'C':
        return Base::C;
    case 'G':
        return Base::G;
    case 'T':
        return Base::T;
    default:
        return std::nullopt;
    }
}

char to_char(Base b) {
    switch (b) {
    case Base::A:
        return 'A';
    case Base::C:
        return 'C';
    case Base::G:
        return 'G';
    case Base::T:
        return 'T';
    }
    __builtin_unreachable();
}

std::ostream &operator<<(std::ostream &os, Base b) { return os << to_char(b); }

} // namespace base
