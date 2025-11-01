#/bin/env python3
def reverse_complement(dna):
    complement = {'A': 'T', 'T': 'A', 'C': 'G', 'G': 'C'}
    reversed_dna = dna[::-1]
    reverse_complement_dna = ''.join(complement[base] for base in reversed_dna)
    return reverse_complement_dna

if __name__ == "__main__":
    sample_dna = open("REVC.txt").read().strip()
    rev_comp = reverse_complement(sample_dna)
    print(rev_comp)
