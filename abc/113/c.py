# -*- coding: utf-8 -*-
from operator import itemgetter

N, M = list(map(int, input().split()))
A = [[0] * 4 for i in range(M)]
for i in range(M):
    A[i][0], A[i][1] = list(map(int, input().split()))
    A[i][2] = i

sorted_A = sorted(A, key=itemgetter(1))

P_num = [1]*N
for a in sorted_A:
    y = a[0]
    a[3] = P_num[y-1]
    P_num[y-1] += 1

B = sorted(sorted_A, key=itemgetter(2))
for b in B:
    print("%06d%06d" % (b[0], b[3]))
