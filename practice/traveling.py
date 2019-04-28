# -*- coding: utf-8 -*-

N = int(input())
time = [0]
place = [[0, 0]]
ans = 'Yes'
for i in range(N):
    t, x, y = map(int, input().split())
    time.append(t)
    place.append([x, y])
    diff_time = time[i+1] - time[i]
    diff_place = place[i+1][0] - place[i][0] + place[i+1][1] - place[i][1]
    if diff_time < diff_place or diff_place % 2 != diff_time % 2:
        ans = 'No'
        break

print(ans)


"""回答"""
# N = int(input())
# for _ in range(N):
#     t, x, y = map(int, input().split())
#     if x + y > t or (t + x + y)%2 != 0:
#         print("No")
#         quit()
# print("Yes")
