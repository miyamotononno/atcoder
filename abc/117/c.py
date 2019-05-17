# -*- coding: utf-8 -*-

N, M = [int(i) for i in input().split()]
X = list(map(int, input().split()))

sorted_X = sorted(X)

diff_list = []
for i, j in zip(sorted_X, sorted_X[1:]):
    diff_list.append(j - i)

ans = sorted(diff_list, reverse=True)[N-1:]
print(sum(ans))
