N = int(input())
S = input()

w = [0]*N
for i in range(1,N):
    #リーダーがi番目にいると仮定
    #リーダーよりにwestにいる人が何人いるか
    if S[i-1] == 'E':
        w[i] = w[i-1]+1
    else:
        w[i] = w[i-1]

e = [0]*N
for i in reversed(range(N)):
    #リーダーがi番目にいると仮定
    #リーダーよりにwestにいる人が何人いるか
    if i==N-1:
        continue

    if S[i+1] == 'W':
        e[i] = e[i+1]+1
    else:
        e[i] = e[i+1]

ans = 1
for i in range(N):
    ans = max(ans, e[i] + w[i]+1) #自分を含める

print(N - ans) 

