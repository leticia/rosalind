#include "GRPH.h"
#include <fstream>
#include <iostream>

// adds a node into the graph and check for adjacent edges.
OverlapGraph &OverlapGraph::operator+=(const Node &node) {
  for (size_t i = 0; i < nodes.size(); ++i) {
    auto &other = nodes[i];
    if (node.dna == other.dna)
      continue; // loop found

    if (node.is_prefix_of(other))
      _edges.emplace_back(nodes.size(), i);

    if (other.is_prefix_of(node))
      _edges.emplace_back(i, nodes.size());
  }

  nodes.emplace_back(node);
  return *this;
}

// returns a lazy view of edges' labels (zero-copy)
std::ranges::view auto OverlapGraph::edges() const {
  return _edges | std::views::transform([&](auto edge) -> Labels {
           auto v = std::get<0>(edge);
           auto w = std::get<1>(edge);
           return {nodes[v].label, nodes[w].label};
         });
}

int main(int argc, char **argv) {
  if (argc != 2) {
    std::cout << "Usage: " << argv[0] << " <file>" << std::endl;
    return 1;
  }

  std::ifstream file(argv[1]);
  std::string line;
  OverlapGraph graph;
  Node node;

  while (std::getline(file, line)) {
    if (line[0] == '>') {
      if (!node.label.empty()) {
        // adds current node to the graph
        graph += node;
      }
      // reset the current node
      node.label = line.substr(1, line.size() - 1);
      node.dna.clear();
    } else {
      // accumulates dna lines;
      node.dna += line;
    }
  }

  // adds last built node to the graph
  graph += node;

  // print out tracked edges
  for (auto edge : graph.edges()) {
    auto v = std::get<0>(edge);
    auto w = std::get<1>(edge);
    std::cout << v << " " << w << std::endl;
  }
}
