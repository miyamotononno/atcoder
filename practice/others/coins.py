# -*- coding: utf-8 -*-

A = int(input())
B = int(input())
C = int(input())
X = int(input())

cnt = 0
for a in range(A+1):
    for b in range(B+1):
        c = (X - a*500 - b*100) / 50
        if c <= C and c >= 0:
            cnt += 1
print(cnt)
