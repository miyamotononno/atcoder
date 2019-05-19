N = int(input())
A = 0
for i in range(N):
    x, u = list(map(str, input().split()))
    if u == 'JPY':
        A += int(x)
    else:
        A += float(x)*380000

print(A)
