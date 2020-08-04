# -*- coding: utf-8 -*-

a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())


def calc(N):
    r = N % 10
    if r == 0:
        r = 10
    count = N + 10 - r
    return r, count


set_list = [a, b, c, d, e]
remainder_list = [0] * 5
counts = [0] * 5

for i in range(5):
    r, count = calc(set_list[i])
    remainder_list[i] = r
    counts[i] = count

print(sum(counts) + min(remainder_list) - 10)
