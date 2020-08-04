S = input()

counts = []
count = 0
for i in range(len(S)):
    if S[i] == 'A' or S[i] == 'C' or S[i] == 'G' or S[i] == 'T':
        count += 1
        if i == len(S) - 1:
            counts.append(count)
    else:
        counts.append(count)
        count = 0

print(max(counts))
