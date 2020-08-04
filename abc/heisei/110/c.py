S = input()
T = input()


def my_index_multi(l, x):
    return [i for i, _x in enumerate(l) if _x == x]


alphabet = [0] * 26
alphabet2 = [0] * 26

for i in range(97, 97+26):
    alphabet[i-97] = my_index_multi(S, chr(i))
    alphabet2[i-97] = my_index_multi(T, chr(i))

ans = 'Yes'
for i in range(26):
    if not alphabet[i]:
        continue
    else:
        if not alphabet[i] in alphabet2:
            ans = 'No'
            break

print(ans)
