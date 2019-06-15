N = int(input())

balls = [[0]*2 for i in range(N)]

for i in range(N):
    balls[i][0], balls[i][1] = list(map(int, input().split()))

balls = sorted(balls, key=lambda x: x[0])
print(balls)

#1個のときは別に処理を書くこと

common_b = 0

for i in range(N):
    for j in range(i+1,N):
        tmp = 0
        if balls[j][0]-balls[i][0] != 0:
            slope = (balls[j][1]-balls[i][1]) / (balls[j][0]-balls[i][0])

            for k in range(N):
                for l in range(k+1, N):
                    if balls[k][0]-balls[l][0] == 0:
                        continue
                    
                    if i== k and j ==l:
                        continue

                    slope2 = (balls[k][1]-balls[l][1]) / (balls[k][0]-balls[l][0])
                    if slope == slope2:
                        tmp+=1

        else:
            for k in range(N):
                for l in range(k+1, N):
                    if i == k and j == l:
                        continue
                    if balls[k][0]-balls[l][0] != 0:
                        continue
                    tmp += 1
                    
        common_b = max(common_b, tmp)

print(N - common_b)
