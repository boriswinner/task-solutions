import math

EPS = 0.00000000001

OUTSIDE = 'OUTSIDE'
OUTER = 'OUTER'
INNER = 'INNER'

class Part():
    x = None
    y = None
    u = None
    v = None
    pos = None

def GetTimeOfCollision(x0, y0, r, p):
    t = math.pow(r, 2) * ( math.pow(p.u, 2) +  math.pow(p.v, 2)) -  math.pow(p.u * (y0 - p.y) - p.v * (x0 - p.x), 2)
    if t < 0:
        return None
    else:
        d =  math.sqrt(t)
    if (d < EPS):
        return None
    t1 = (p.u * (x0 - p.x) + p.v * (y0 - p.y) - d) / (math.pow(p.u, 2) + math.pow(p.v, 2))
    t2 = (p.u * (x0 - p.x) + p.v * (y0 - p.y) + d) / (math.pow(p.u, 2) + math.pow(p.v, 2))
    if (min(t1, t2) > EPS):
        return min(t1, t2)
    elif (max(t1, t2) > EPS):
        return max(t1, t2)
    else:
        return None

with open('input.txt',) as inp:
    s = inp.readline().split()
    x0 = float(s[0])
    y0 = float(s[1])
    r1 = float(s[2])
    r2 = float(s[3])
    s = inp.readline().split()
    t = float(s[0])
    m = int(s[1])
    s = inp.readline().split()
    n = int(s[0])
    parts = []
    for i in range(n):
        parts.append(Part())
    for i in range(n):
        s = inp.readline().split()
        parts[i].x = float(s[0])
        parts[i].y = float(s[1])
        parts[i].u = float(s[2])
        parts[i].v = float(s[3])
        if ( math.pow(parts[i].x - x0, 2) +  math.pow(parts[i].y - y0, 2) <  math.pow(r1, 2)):
            parts[i].pos = INNER
        elif ( math.pow(parts[i].x - x0, 2) +  math.pow(parts[i].y - y0, 2) <  math.pow(r2, 2)):
            parts[i].pos = OUTER
        else:
            parts[i].pos = OUTSIDE

with open('output.txt', 'w') as outp:
    for i in range(m):
        for j in range(n):
            deltaT = t / float(m)
            if (abs(parts[j].u) > EPS or abs(parts[j].v) > EPS):
                while (deltaT > EPS):
                    collisionTime = None
                    if (parts[j].pos == INNER):
                        collisionTime = GetTimeOfCollision(x0, y0, r1, parts[j])
                    elif (parts[j].pos == OUTER):
                        ct1 = GetTimeOfCollision(x0, y0, r1, parts[j])
                        ct2 = GetTimeOfCollision(x0, y0, r2, parts[j])
                        if (ct1 == None):
                            collisionTime = ct2
                        elif (ct2 == None):
                            collisionTime = ct1
                        else:
                            collisionTime = min(ct1, ct2)
                    else:
                        collisionTime = GetTimeOfCollision(x0, y0, r2, parts[j])

                    if (collisionTime == None or collisionTime - deltaT > EPS):
                        parts[j].x += parts[j].u * deltaT
                        parts[j].y += parts[j].v * deltaT
                        break 
                    else:
                        deltaT -= collisionTime
                        parts[j].x += parts[j].u * collisionTime
                        parts[j].y += parts[j].v * collisionTime
                        xnn = (x0 - parts[j].x) /  math.sqrt((x0 - parts[j].x)*(x0 - parts[j].x) + (y0 - parts[j].y)*(y0 - parts[j].y)) 
                        ynn = (y0 - parts[j].y) /  math.sqrt((x0 - parts[j].x)*(x0 - parts[j].x) + (y0 - parts[j].y)*(y0 - parts[j].y)) 
                        d = (parts[j].u * xnn + parts[j].v * ynn) 
                        parts[j].u -= 2.0 * d * xnn 
                        parts[j].v -= 2.0 * d * ynn 
            outp.write("%.5f %.5f\n" % (parts[j].x, parts[j].y))
