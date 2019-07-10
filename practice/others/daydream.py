# -*- coding: utf-8 -*-

given = ["dreamer", "dream", "eraser", "erase"]
S = input()
while len(S) > 0:
    judge = [S.endswith(i) for i in given]  # endswithで指定文字列で終わるか真偽値で返す
    if any(judge):
        target = given[judge.index(True)]
        S = S[:-len(target)]
        if len(S) == 0:
            print("YES")
            break
    else:
        print("NO")
        break
