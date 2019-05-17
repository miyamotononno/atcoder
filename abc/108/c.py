N, K = list(map(int, input().split()))

ans = 0
a = N // K

if K % 2 != 0:
    ans = a**3
else:
    if N / K - N//K < 0.5:
        ans = 2 * a**3
    else:
        ans = a**3 + (a+1)**3

print(ans)
