N = int(input())

ans = 0
for i in range(N):
    A, B = [int(t) for t in input().split()]
    if A >= 2*B:
        ans += B
    else:
        ans += A//2

print(ans)
