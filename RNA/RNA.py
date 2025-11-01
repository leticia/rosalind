#/bin/env python3
def transcribe(dna):
    return dna.replace('T', 'U')

if __name__ == "__main__":
    sample_dna = open("rosalind_rna.txt").read().strip()
    rna = transcribe(sample_dna)
    print(rna)
