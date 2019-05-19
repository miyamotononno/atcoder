S = input()

j = [0, 0]
a = int(S[:2])
b = int(S[2:])


def judge(num):
    if num > 0 and num < 13:
        return True
    else:
        return False


if judge(a) and judge(b):
    print('AMBIGUOUS')
elif not judge(a) and not judge(b):
    print('NA')
elif judge(a) and not judge(b):
    print('MMYY')
elif not judge(a) and judge(b):
    print('YYMM')
