#bin/env python3
def rabbit_pairs(n, k):
    if n == 1 or n == 2:
        return 1

    rabbits = [0] * n
    rabbits[0] = 1  # Month 1
    rabbits[1] = 1  # Month 2

    for month in range(2, n):
        rabbits[month] = rabbits[month - 1] + k * rabbits[month - 2]

    return rabbits[-1]

if __name__ == "__main__":
    with open("rosalind_fib.txt") as f:
        data = f.read().strip()
    n, k = map(int, data.split())
    total_rabbits = rabbit_pairs(n, k)
    print(total_rabbits)
