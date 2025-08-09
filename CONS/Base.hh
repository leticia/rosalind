#pragma once

#include <array>
#include <optional>
#include <ostream>

namespace base {

enum class Base { A, C, G, T };

constexpr std::array<Base, 4> All = {Base::A, Base::C, Base::G, Base::T};
constexpr size_t N = All.size();

std::optional<Base> from_char(char);
char to_char(Base);

std::ostream &operator<<(std::ostream &, Base);

} // namespace base
