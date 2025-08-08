#pragma once

#include <ranges>
#include <string>
#include <string_view>
#include <tuple>
#include <vector>

constexpr int k = 3;

using Label = const std::string &;
using Labels = const std::tuple<Label, Label>;

struct Node {
  std::string label, dna;

  bool is_prefix_of(const Node &other) const {
    // use zero-copy substrings for efficiency
    std::string_view suffix(dna.c_str() + (dna.length() - k), k);
    std::string_view prefix(other.dna.c_str(), k);
    return suffix == prefix;
  }
};

class OverlapGraph {
private:
  std::vector<Node> nodes;
  std::vector<std::tuple<int, int>> _edges;

public:
  OverlapGraph &operator+=(const Node &);
  std::ranges::view auto edges() const;
};
