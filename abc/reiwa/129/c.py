N, M = list(map(int, input().split()))
A =[0]*M
for i in range(M):
    A[i] = int(input())

amari = 1000000007
cnt = [0]*(N+2)
cnt[0] = 0
cnt[1] = 1
for i in range(2,N+2):
    t = (cnt[i-1]+cnt[i-2])
    cnt[i] = t % amari

ans = 1
def calc(ans):
    if M == 0:
        return cnt[N+1]

    for i in range(M): 
        if i == 0:
            ans*= cnt[A[i]]
        elif i > 0 and i < M:
            ans*=cnt[A[i] - A[i-1]-1]

        if i == M-1:
            ans*= cnt[N - A[i]]
        
        if ans == 0:
            break
    
        ans %= amari
        
    return ans

print(calc(ans))