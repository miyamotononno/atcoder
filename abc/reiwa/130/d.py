N, K = list(map(int, input().split()))
A = list(map(int, input().split()))
sum_A = [0]*(N+1)
sum_A[0] = 0
cnt = 0
left = 0
for i in range(1,N+1):
    sum_A[i] = sum_A[i-1] + A[i-1]
    if sum_A[i] - sum_A[left] >=K:
        cnt+=N-i+1
        left+=1
        while sum_A[i] - sum_A[left] >=K:
            cnt+=N-i+1
            left+=1
            
print(cnt)