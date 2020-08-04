N = int(input())
obj = {}
for i in range(N):
  s = input()

  w = ''.join(sorted(list(s)))
  if not obj.get(w):
    obj[w] = 1
  else:
    obj[w] += 1

cnt = 0
for i in obj:
  v = obj[i]
  cnt += (v*(v-1))/2

print(int(cnt))
  