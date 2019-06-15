N, H = list(map(int, input().split()))

mx = N - (H-1)
if H > 1:
    print(mx -1)
else:
    print(0)