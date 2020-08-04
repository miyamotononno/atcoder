N, M = [int(t) for t in input().split()]
l = [[0]*2 for i in range(M)]

l_max = 0
r_min = N
for i in range(M):
    L, R = [int(t) for t in input().split()]
    l_max = L if l_max < L else l_max
    r_min = R if r_min > R else r_min

ans = r_min-l_max+1 if r_min >= l_max else 0
print(ans)
