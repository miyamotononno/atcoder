import math
N, K = list(map(int, input().split()))


def calc(ini):
    l = math.ceil(math.log2(K/ini))
    return 0.5**l


ans = 0
for i in range(1, N+1):
    if i >= K:
        ans += 1/N
    else:
        ans += calc(i)/N

print(ans)
