# -*- coding: utf-8 -*-
from operator import itemgetter


N, M = list(map(int, input().split()))

a = [0] * N
for i in range(N):
    a[i] = list(map(int, input().split()))


def main():
    b = sorted(a, key=itemgetter(0))
    m = 0
    cost = 0
    for i in range(N):
        if (m + b[i][1]) <= M:
            m += b[i][1]
            cost += (b[i][0] * b[i][1])
        else:
            cost += (b[i][0] * (M-m))
            return cost
    return cost


print(main())
