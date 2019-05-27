import fractions as fr
N = int(input())
for i in range(N):
    A, B = [int(t) for t in input().split()]
    print(fr.gcd(A, B))
