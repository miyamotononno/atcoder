N = int(input())
L = [[0]*3 for i in range(N)]

for i in range(N):
    S, P = map(str, input().split())
    P = int(P)
    L[i][0] = S
    L[i][1] = P
    L[i][2] = i+1

tmp = sorted(L, key=lambda x: x[1], reverse=True)
ans = sorted(tmp, key=lambda x: x[0])
for a in ans:
    print(a[2])
