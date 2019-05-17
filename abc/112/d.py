# -*- coding: utf-8 -*-

N, M = list(map(int, input().split()))


def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)

    divisors.sort()
    return divisors


F = make_divisors(M)
gcd = 1

for i in range(len(F)):
    if F[i] * N > M:
        break

    gcd = F[i]

print(gcd)
