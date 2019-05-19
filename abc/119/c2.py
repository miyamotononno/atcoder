N, A, B, C = list(map(int, input().split()))
l = [0]*N
for i in range(N):
    l[i] = int(input())


def dfs(a, b, c, i):
    if i == N:
        if a == 0 or b == 0 or c == 0:  # 最低竹は各一本ずつある
            return 1e9

        return abs(A - a) + abs(B - b) + abs(C - c)

    dfs_not_used = dfs(a, b, c, i+1)
    dfs_A = dfs(a+l[i], b, c, i+1) + + 10*(a != 0)  # 元々なにもないとき、合成魔法を使う必要がない
    dfs_B = dfs(a, b+l[i], c, i+1) + 10*(b != 0)
    dfs_C = dfs(a, b, c+l[i], i+1) + 10*(c != 0)

    return min(dfs_not_used, dfs_A, dfs_B, dfs_C)


ans = dfs(0, 0, 0, 0)
print(ans)
