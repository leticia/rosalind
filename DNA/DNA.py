#/bin/env python3
def count_nucleotides(dna):
    a_count = dna.count('A')
    c_count = dna.count('C')
    g_count = dna.count('G')
    t_count = dna.count('T')
    return a_count, c_count, g_count, t_count

if __name__ == "__main__":
    sample_dna = open("DNA.txt").read().strip()
    a, c, g, t = count_nucleotides(sample_dna)
    print(a, c, g, t)
