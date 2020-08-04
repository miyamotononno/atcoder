import fractions

N, X = list(map(int, input().split()))

x = list(map(int, input().split()))
d = 0
for i in range(N):
    if i == 0:
        d = abs(x[i] - X)
    else:
        d = fractions.gcd(d, abs(x[i] - X))

print(d)
