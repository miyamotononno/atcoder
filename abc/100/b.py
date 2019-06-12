D, N = list(map(int, input().split()))

ans = 0
if N < 100:
    ans = 100**D * N
else: 
    ans = 100**D * (N+1)
print(ans)