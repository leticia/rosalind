#bin/env python3
def permutations(elements):
    if len(elements) == 0:
        return [[]]
    result = []
    for i in range(len(elements)):
        current = elements[i]
        remaining = elements[:i] + elements[i+1:]
        for p in permutations(remaining):
            result.append([current] + p)
    return result

if __name__ == "__main__":
    n = 5
    elements = range(1, n + 1)
    permutations = permutations(list(elements))
    print(len(permutations))
    for permutation in permutations:
        print(' '.join(map(str, permutation)))
