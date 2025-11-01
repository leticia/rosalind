#bin/env python3
if __name__ == "__main__":
    with open("GC.txt", "r") as file:
        fasta = file.read().strip().split('>')
        max_gc_id = ""
        max_gc_percentage = 0.0
        for entry in fasta:
            if entry:
                lines = entry.splitlines()
                ID = lines[0].strip()
                sequence = ''.join(lines[1:]).replace('\n', '').strip()
                gc_count = sequence.count('G') + sequence.count('C')
                gc_percentage = (gc_count / len(sequence)) * 100

                if gc_percentage > max_gc_percentage:
                    max_gc_percentage = gc_percentage
                    max_gc_id = ID
        print(max_gc_id)
        print(f"{max_gc_percentage:.6f}")
