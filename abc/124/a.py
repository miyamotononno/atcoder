# -*- coding: utf-8 -*-

A, B = map(int, input().split())

count = 0
if A >= B:
    count += A
    A -= 1
else:
    count += B
    B -= 1

if A >= B:
    count += A
    A -= 1
else:
    count += B
    B -= 1

print(count)
