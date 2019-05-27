r, D, x = [int(t) for t in input().split()]
ans = x
for i in range(10):
    ans = r*ans - D
    print(ans)
