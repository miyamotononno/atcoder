# -*- coding: utf-8 -*-

N, K = [int(i) for i in input().split()]
h = [int(input()) for i in range(N)]

sorted_tree = sorted(h)
sorted_tree2 = sorted_tree[K-1:]

min_diff = 1e9
for (min_h, max_h) in zip(sorted_tree, sorted_tree2):
    if (max_h - min_h) < min_diff:
        min_diff = max_h - min_h

print(min_diff)
