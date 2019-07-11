N = int(input())

ans = 0
for i in range(N):
    A, B = [int(t) for t in input().split()]
    if ans < A+B:
        ans = A+B

print(ans)
