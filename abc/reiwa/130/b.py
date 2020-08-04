N, X = list(map(int, input().split()))
L = list(map(int, input().split()))

cnt = 1
height= 0
for i in range(N):
    height = height+ L[i]
    if height <= X:
        cnt+=1
    else:
        break

print(cnt)