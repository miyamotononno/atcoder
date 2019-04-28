# -*- coding: utf-8 -*-
import fractions

N = int(input())
A = list(map(int, input().split()))


gcd = fractions.gcd


left = [0] * N
right = [0] * N
for i in range(N):
    if i == 0:
        left[0] = A[0]
        right[N-1] = A[-1]
        continue

    left[i] = gcd(left[i-1], A[i])
    right[N-i-1] = gcd(right[N-i], A[N-i-1])

max_gcd = right[1]
for i in range(N):
    if i == 0:
        continue
    elif i == N - 1:
        if max_gcd < left[-2]:
            max_gcd = left[-2]
    else:
        target = gcd(left[i-1], right[i+1])
        if max_gcd < target:
            max_gcd = target

print(max_gcd)
