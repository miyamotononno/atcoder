# -*- coding: utf-8 -*-

N = int(input())
s = [input() for i in range(N)]

cnt = 0
both_ab = 0
last_a = 0
initial_b = 0
for i in range(N):
    if s[i].count('AB') > 0:
        cnt += s[i].count('AB')

    if s[i][-1] == 'A' and s[i][0] == 'B':
        both_ab += 1
    elif s[i][-1] == 'A':
        last_a += 1
    elif s[i][0] == 'B':
        initial_b += 1


def calc(cnt, both_ab, last_a, initial_b):
    if both_ab == 0:
        min_a_b = min(initial_b, last_a)
        cnt += min_a_b
        return cnt

    if min(both_ab, last_a) > min(both_ab, initial_b):
        cnt += min(both_ab, initial_b)
        both_ab -= min(both_ab, initial_b)
    else:
        cnt += min(both_ab, last_a)
        both_ab -= min(both_ab, last_a)

    if last_a == 0 and initial_b == 0:
        return cnt + both_ab - 1

    min_a_b = min(initial_b, last_a)
    cnt += min_a_b

    return both_ab + cnt


ans = calc(cnt, both_ab, last_a, initial_b)
print(ans)
