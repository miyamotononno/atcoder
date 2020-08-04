N, M = map(int, input().split())
A = list(map(int, input().split()))
p = [(A[i], 1) for i in range(N)]
for j in range(M):
    B, C = map(int, input().split())
    p.append((C, B))

p.sort(reverse=True)
ans, cnt = 0, N
for (v, c) in p:
    use = min(c, cnt)
    ans += use * v
    cnt -= use
print(ans)
