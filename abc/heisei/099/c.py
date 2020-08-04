N = int(input())

L =[1,6**1,6**2,6**3,6**4,6**5,6**6,9**1,9**2,9**3,9**4,9**5]
X = [0]*(N+1)
for i in range(1, N+1):
    X[i] = 100000

for i in range(N+1):
    for l in L:
        if i+l <= N:
            X[i+l] = min(X[i] + 1, X[i+l])
        
print(X[-1])
