n = int(input())
A = [0]*n
for i in range(n):
  d = int(input())
  A[d-1]+=1

x=-1
y=-1
for i in range(n):
  if A[i]==1:
    continue
  
  if A[i]==2:
    y = i+1
  else:
    x = i+1
  
if x<0:
  print("Correct")
else:
  print("{0} {1}".format(y, x))