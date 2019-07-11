N = int(input())

ans = 0
for i in range(N):
    A, B = [int(t) for t in input().split()]
    ans += max(A, B)

print(ans)
