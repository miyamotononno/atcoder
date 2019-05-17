# -*- coding: utf-8 -*-
import math

N = int(input())

m = math.floor(N ** 0.5) + 1

ans = 0
for i in range(1, m):
    if N % i == 0 and i < (N // i) - 1:
        ans += (N // i - 1)

print(ans)
