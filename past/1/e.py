N, Q = list(map(int, input().split()))

f = [['N']*N for i in range(N)]

def ff(orig, target):
  for i in range(N):
    if i == orig or i==target:
      continue
    if f[target][i] == 'Y':
      f[orig][i] = 'Y'

for _ in range(Q):
  L = list(map(int, input().split()))
  a = L[1]
  a-=1
  if L[0] == 1:
    f[a][L[2]-1] = 'Y'
  
  elif L[0] == 2:
    for i in range(N):
      if f[i][a] == 'Y':
        f[a][i] = 'Y'
  
  elif L[0] == 3:
    g = f[a].copy()
    for tar in range(N):
      if g[tar] == 'Y':
        ff(a, tar)

for i in range(N):
  t = ""
  for j in range(N):
    t+=f[i][j]
  print(t)