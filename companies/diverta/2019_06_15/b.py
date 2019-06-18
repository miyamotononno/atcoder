N = int(input())
 
balls = [[0]*2 for i in range(N)]
 
for i in range(N):
    balls[i][0], balls[i][1] = list(map(int, input().split()))
 
common_b = 0
 
for i in range(N):
    for j in range(i+1, N):
 
        tmp = 1
        x_base = balls[j][0]-balls[i][0]
        y_base = balls[j][1]-balls[i][1]
        for k in range(i+1,N):
            for l in range(k+1, N):
 
                if balls[l][1]-balls[k][1] == y_base and balls[l][0]-balls[k][0] == x_base:
                    tmp+=1
                    
        common_b = max(common_b, tmp)
 
print(N - common_b)
