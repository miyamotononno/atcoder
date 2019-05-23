S = input()


def judge(s):
    if s[0] != 'A':
        return 'WA'

    if S[2:-1].count('C') != 1:
        return 'WA'

    t = s.find('C')
    s[1:t]

    return 'AC' if s[1:t].islower() and s[t+1:].islower() else 'WA'


print(judge(S))
