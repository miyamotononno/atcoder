import math
N, K = [int(t) for t in input().split()]
A = [int(t) for t in input().split()]

print(math.ceil((N - 1) / (K-1)))
