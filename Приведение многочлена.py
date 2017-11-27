with open ('input.txt','r') as fin:
    indata = fin.read().split()
indata = [int(i) for i in indata]
p = int(indata[0])
n = int(indata[1])
indata = indata[2:]

ans = [0 for i in range(n+1)]
ans[0] = int(indata[0])

for i in range(1, n + 1):
    ans[i] = ans[i - 1]
    for k in range(i - 1, 0, -1):
        ans[k] = (ans[k - 1] - (indata[i] * ans[k]) % p) % p
    ans[0] = (-1) * indata[i] * ans[0] % p

with open ('output.txt','w') as fout:
    for j in ans:
        fout.write(str(j) + '\n')
