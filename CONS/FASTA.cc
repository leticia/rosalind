#include "FASTA.hh"
#include <limits>

using stream_sz = std::numeric_limits<std::streamsize>;

namespace fasta {

void skip_label_line(std::istream &input) {
    if (input.peek() == '>')
        input.ignore(stream_sz::max(), '\n');
}

std::string next_dna_string(std::istream &input) {
    fasta::skip_label_line(input);
    std::string dna, line;
    do {
        if (std::getline(input, line))
            dna += line;
    } while (input && input.peek() != '>');
    return dna;
}

} // namespace fasta
