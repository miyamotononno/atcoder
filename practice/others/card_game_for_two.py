# -*- coding: utf-8 -*-

N = int(input())
A = list(map(int, input().split()))
A.sort(reverse=True)
alice = 0
bob = 0
for i in range(len(A)):
    if i % 2 == 0:
        alice += A[i]
    else:
        bob += A[i]
print(alice-bob)


"""回答"""
# N = int(input())
# l = list(map(int, input().split()))
# l.sort(reverse=True)
# print(sum(l[0::2]) - sum(l[1::2]))
