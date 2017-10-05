import math

with open ('input.txt') as fin:
    tn, tm = [int(t) for t in next(fin).split()]
    s = fin.readline()
res = 0
curres = 0
prevres = 0
k = 0
was_non_zero_c = False
for i in range(len(s)-1,-1,-1):
    n = len(s)-1 - i
    if s[i] == '1': k += 1
    if (n < k): continue
    if (not was_non_zero_c):
        curres = int(int(math.factorial(n)) // int((math.factorial(n - k)) * int(math.factorial(k))))
        if (curres != 0): was_non_zero_c = True
    else:
        if ((n + 1 - k == 0) and (s[i] == '0')) or ((k + 1 == 0) and (s[i] == '1')):
            curres = 0
        else:
            if (s[i] == '1'):
                curres = int(prevres * int(n) // int(k))
            else:
                curres = int(prevres * int(n) // int(n - k))
    if s[i] == '1':
        res += curres
    prevres = curres
with open('output.txt', 'w') as fout:
    fout.write(bin(res)[2:])
