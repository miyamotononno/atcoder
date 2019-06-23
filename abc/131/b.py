N, L = list(map(int, input().split()))

A = [0]*N
sm = 0
m = -100
for i in range(N):
    A[i] = L+i
    sm+= L+i
    if L+i == 0:
        m = i 

if m >=0:
    print(sm)
elif L > 0:
    print(sm-A[0])
elif L+N-1 <0:
    print(sm-A[-1])