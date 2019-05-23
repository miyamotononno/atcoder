

# 解き直すこと！！！！！！
from math import ceil

D, G = [int(t) for t in input().split()]
p = []
c = []
for i in range(D):
    p_, c_ = [int(t) for t in input().split()]
    p.append(p_)
    c.append(c_)


def minsolve(G, i):
    """100i点以下の問題だけでGを達成する最小問題数"""
    if i <= 0:
        return float('inf')
    n = min(ceil(G / (100 * i)), p[i-1])
    s = 100 * i * n
    if n == p[i-1]:
        s += c[i-1]
    m = n if s >= G else n + minsolve(G - s, i-1)
    return min(m, minsolve(G, i-1))


print(minsolve(G, D))
