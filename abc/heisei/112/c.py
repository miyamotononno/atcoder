# -*- coding: utf-8 -*-

n = int(input())
li = [list(map(int, input().split())) for i in range(n)]
li.sort(key=lambda x: x[2])
a, b, c = li[-1]
for x in range(101):
    for y in range(101):
        h = abs(x-a) + abs(y-b) + c
        if all(k == max(h-abs(x-i)-abs(y-j), 0) for i, j, k in li):
            print(x, y, h)
            exit()
