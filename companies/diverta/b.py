# -*- coding: utf-8 -*-

R, G, B, N = [int(i) for i in input().split()]

cnt = 0
for i in range(N // R + 1):
    r = i * R
    for j in range((N - r) // G + 1):
        g = j * G

        b = N - r - g

        if b % B == 0:
            cnt += 1

print(cnt)
