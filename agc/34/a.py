if __name__ == '__main__':
    N, A, B, C, D = map(int, input().split())
    S = str(input())
 
    answer = "-1"
 
    if C < D:
       if S[A:D:].count("##") >= 1:
           answer = "No"
       else:
           answer = "Yes"
    else:
       if S[B-2:D+1:].count("...") >= 1:
           answer = "Yes"
       else:
           answer = "No"
 
    print(answer)


