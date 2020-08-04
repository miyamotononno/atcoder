N = int(input())
W = list(map(int, input().split()))

ans = 10000000
for i in range(N):
    ans = min(abs(sum(W[:i])-sum(W[i:])),ans)

print(ans)