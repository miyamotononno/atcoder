N = int(input())
A = list(map(int, input().split()))

cnt = 0
for i in range(N):
    a = A[i]
    while a %2 ==0:
        cnt+=1
        a /= 2
    
print(cnt)