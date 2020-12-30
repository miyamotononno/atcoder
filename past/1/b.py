n = int(input())
A = [0]*n
for i in range(n):
  A[i] = int(input())

for i in range(n-1):
  d = A[i+1]-A[i]
  ans = ""
  if d == 0:
    ans = "stay"
    print(ans)
    continue
  
  if d<0:
    ans = "down"
  else:
    ans = "up"
  
  print("{0} {1}".format(ans, abs(d)))