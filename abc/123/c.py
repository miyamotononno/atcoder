# -*- coding: utf-8 -*-
import math

N = int(input())
a = int(input())
b = int(input())
c = int(input())
d = int(input())
e = int(input())

traffics = [a, b, c, d, e]
min_traffic = min(traffics)
ans = math.ceil(N / min_traffic) + 4
print(ans)
