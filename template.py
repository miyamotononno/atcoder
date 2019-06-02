# 文字列の入力
S = input()
# 整数の入力
N = int(input())

# 整数が複数
L = list(map(int, input().split()))
#二つだと限定されている
N, H = list(map(int, input().split()))

# それ以外
L = list(map(str, input().split()))

# 入力が複数行に渡っている時
for i in range(N):
    N = int(input())
    # N, H = list(map(int, input().split()))

#for文で二次元配列を初期化(M*N)
M = 0
L = [[0]*M for i in range(N)]