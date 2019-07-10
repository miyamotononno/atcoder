# -*- coding: utf-8 -*-

N, A, B = map(int, input().split())
C = 0
for i in range(N):
    n = str(i+1)
    c = 0
    for j in range(len(n)):
        c += int(n[j])
    if c >= A and c <= B:
        C += i+1

print(C)

"""回答"""
# N, A, B = map(int, input().split())
# res = 0
# for i in range(N+1):
#     if A <= sum([int(s) for s in str(i)]) <= B:
#         res += i
# print(res)
