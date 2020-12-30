S = input()

T = []
s =""
for i in range(len(S)):
  if S[i].isupper() and len(s)>0:
    s+=S[i]
    T.append(s)

    s=""
  else:
    s+=S[i].upper()

T.sort()
ans = ""
for txt in T:
  t = list(txt)
  ans+=t[0]
  if len(t)>2:
    for i in range(1, len(t)-1):
      ans+=t[i].lower()
  ans+=t[len(t)-1]

print(ans)
