import collections
c = collections.Counter

S =input()
T = ['']*4
for i in range(4):
    T[i] = S[i]

t = c(T).most_common()
if len(t) == 2 and t[0][1] ==2:
    print('Yes')
else:
    print('No') 