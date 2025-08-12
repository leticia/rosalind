#pragma once

#include <istream>
#include <string>

namespace fasta {

void skip_label_line(std::istream &);

std::string next_dna_string(std::istream &);

} //  namespace fasta
