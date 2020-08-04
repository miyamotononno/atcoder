N, M = [int(t) for t in input().split()]
a = [[0]*2 for i in range(M)]
for i in range(M):
    a[i][0], a[i][1] = [int(t) for t in input().split()]

b = sorted(a, key=lambda x: x[1])

count = 1
flag = b[0][1]
for i in range(1, M):
    if b[i][0] < flag:
        continue
    elif b[i][1] > flag:
        flag = b[i][1]
        count += 1

print(count)
