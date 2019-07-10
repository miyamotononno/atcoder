# -*- coding: utf-8 -*-

N = int(input())
d = []
for _ in range(N):
    d.append(int(input()))
print(len(set(d)))


"""回答"""
# N = int(input())
# l = sorted([input() for _ in range(N)])
# print(len(set(l)))
