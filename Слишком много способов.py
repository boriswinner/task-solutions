import math
with open('input.txt') as f:
    xm,ym,zm,xb,yb,zb = [int(x1) for x1 in f.readline().split()]
x = abs(xm-xb)
y = abs(ym-yb)
z = abs(zm-zb)
f2 = open('output.txt','w')
answer = int(math.factorial(x+y+z) // (math.factorial(x)*math.factorial(y)*math.factorial(z)))%int(1000000007)
f2.write(str(int(answer)))
