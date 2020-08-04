# -*- coding: utf-8 -*-

a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())
k = int(input())


def calc(m, n):
    return True if n - m > k else False


set_list = [(a, b), (a, c), (a, d), (a, e), (b, c),
            (b, d), (b, e), (c, d), (c, e), (d, e)]

ans = 'Yay!'
for i in range(len(set_list)):
    m, n = set_list[i]
    if calc(m, n):
        ans = ':('
        break

print(ans)
