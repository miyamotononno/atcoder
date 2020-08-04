N, M = list(map(int, input().split()))

C = [[0]*3 for i in range(N)]
for i in range(N):
    x, y, z = list(map(int, input().split()))
    C[i][0] = x
    C[i][1] = y
    C[i][2] = z

#0なら負、1なら正
def calc(pn_x,pn_y,pn_z):
    L = [0]*N
    for i in range(N):
        x= C[i][0] if pn_x else (-1)*C[i][0]
        y= C[i][1] if pn_y else (-1)*C[i][1]
        z= C[i][2] if pn_z else (-1)*C[i][2]
        L[i] = x + y + z

    L = sorted(L, reverse=True)
    return sum(L[:M])


ans = 0
for i in range(2):
    for j in range(2):
        for k in range(2):
            ans = max(ans,calc(i,j,k))

print(ans)

            