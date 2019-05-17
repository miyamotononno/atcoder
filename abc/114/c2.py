# -*- coding: utf-8 -*-

N = input()


def calc_without_375(n):
    if n < 357:
        return 0
    elif 357 <= n < 375:
        return 1
    elif 375 <= n < 537:
        return 2
    elif 537 <= n < 573:
        return 3
    elif 573 <= n < 735:
        return 4
    elif 735 <= n < 753:
        return 5
    else:
        return 6


def calc_without_57(n):
    if n < 557:
        return calc_without_375(n)
    elif 557 <= n < 575:
        return 1 + calc_without_375(n)
    elif 575 <= n < 577:
        return 2 + calc_without_375(n)
    elif 577 <= n < 755:
        return 3 + calc_without_375(n)
    elif 755 <= n < 757:
        return 4 + calc_without_375(n)
    elif 757 <= n < 775:
        return 5 + calc_without_375(n)
    elif 775 <= n:
        return 6 + calc_without_375(n)


def calc_without_35(n):
    if n < 335:
        return calc_without_375(n)
    elif 335 <= n < 353:
        return 1 + calc_without_375(n)
    elif 353 <= n < 355:
        return 2 + calc_without_375(n)
    elif 355 <= n < 533:
        return 3 + calc_without_375(n)
    elif 533 <= n < 535:
        return 4 + calc_without_375(n)
    elif 535 <= n < 553:
        return 5 + calc_without_375(n)
    elif 553 <= n:
        return 6 + calc_without_375(n)


def calc_without_37(n):
    if n < 337:
        return calc_without_375(n)
    elif 337 <= n < 373:
        return 1 + calc_without_375(n)
    elif 373 <= n < 377:
        return 2 + calc_without_375(n)
    elif 377 <= n < 733:
        return 3 + calc_without_375(n)
    elif 733 <= n < 737:
        return 4 + calc_without_375(n)
    elif 737 <= n < 773:
        return 5 + calc_without_375(n)
    elif 773 <= n:
        return 6 + calc_without_375(n)


def calc_without_3(n):
    r = calc_without_35(n) + calc_without_37(n) - calc_without_375(n)
    return r if n < 333 else r+1


def calc_without_5(n):
    r = calc_without_35(n) + calc_without_57(n) - calc_without_375(n)
    return r if n < 555 else r+1


def calc_without_7(n):
    r = calc_without_37(n) + calc_without_57(n) - calc_without_375(n)
    return r if n < 777 else r+1


def calc_has_all(n):
    return calc_without_3(n) + calc_without_5(n) + calc_without_7(n) - calc_without_35(n) - calc_without_37(n) - calc_without_57(n) + calc_without_375(n)


def calc_last3digits(has3, has5, has7, n):
    if has3 and has5 and has5:
        return calc_has_all(n)

    if has3 and has5:
        return calc_without_7(n)
    elif has5 and has7:
        return calc_without_3(n)
    elif has3 and has7:
        return calc_without_5(n)

    if has3:
        return calc_without_57(n)
    elif has5:
        return calc_without_37(n)
    elif has7:
        return calc_without_35(n)

    return calc_without_375(n)


def calc_sum(d):
    return 3**(d - 1) - 3*2**(d - 1) + 3


def calc(has3, has5, has7, str_num):
    digits = len(str_num)
    if digits == 3:
        return calc_last3digits(has3, has5, has7, int(str_num))

    # 一つ下の位の数の総和
    base = 3**(digits - 1) - 3*2**(digits - 1) + 3

    # 1番位の高い数で場合分け
    p = int(str_num[0])
    if p >= 3:
        base += calc(True, has5, has7, str_num[1:])
    elif p >= 5:
        base += calc(has3, True, has7, str_num[1:])
    elif p >= 7:
        base += calc(has3, has5, True, str_num[1:])

    return base


ans = calc(False, False, False, N)
print(ans)
