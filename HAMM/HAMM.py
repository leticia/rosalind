#bin/env python3
import sys

def hamming_distance(seq1, seq2):
    if len(seq1) != len(seq2):
        print("Sequences are of unequal length.")
        sys.exit(1)

    distance = sum(n1 != n2 for n1, n2 in zip(seq1, seq2))
    return distance

if __name__ == "__main__":
    with open("rosalind_hamm.txt") as f:
        data = f.read().strip().splitlines()
    sequence_1 = data[0]
    sequence_2 = data[1]
    distance = hamming_distance(sequence_1, sequence_2)
    print(distance)
