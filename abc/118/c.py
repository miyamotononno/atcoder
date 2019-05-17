# -*- coding: utf-8 -*-

N = int(input())
A = list(map(int, input().split()))


def calc(monsters):
    if len(monsters) == 1:
        return monsters[0]

    min_monster = min(monsters)
    min_index = monsters.index(min_monster)
    new_monsters = []
    for i in range(len(monsters)):
        if i == min_index:
            new_monsters.append(monsters[i])

        remndr = monsters[i] % min_monster
        if remndr != 0:
            new_monsters.append(remndr)

    return calc(new_monsters)


ans = calc(A)
print(ans)
