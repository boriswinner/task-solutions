with open('input.txt', 'r') as inp:
    s = inp.readline().split()
    n = int(s[0])
    m = int(s[1])
    columnsTypes = inp.readline().split()
    priorities = [int(i) for i in inp.readline().split()]
    records = []
    for i in range(n):
        t = []
        for j in range(m):
            ts = [priorities[j],inp.readline().replace('\r', '').replace('\n', '')]
            t.append(ts)
        t.sort(reverse=True)
        t = [i[1] for i in t]
        t.append(i)
        records.append(t.copy())
    prioritiesColTypes = [[priorities[i],columnsTypes[i]] for i in range(len(priorities))]
    prioritiesColTypes.sort(reverse=True)
    priorities.sort(reverse=True)
    for i in range(len(records[0])-2,-1,-1):
        if (prioritiesColTypes[i][1] == 's'):
            records = sorted(records, key=lambda x: x[i])
        elif (prioritiesColTypes[i][1]  == 'd'):
            records = sorted(records, key=lambda x: float(x[i]))
        elif (prioritiesColTypes[i][1]  == 'i'):
            records = sorted(records, key=lambda x: int(x[i]), reverse = True)
        elif (prioritiesColTypes[i][1]  == 'u'):
            records = sorted(records, key=lambda x: int(x[i]))
        elif (prioritiesColTypes[i][1]  == 'c'):
            records = sorted(records, key=lambda x: ord(x[i][0]), reverse = True)
with open('output.txt', 'w') as outp:
    for i in range(len(records)):
        outp.write(str(records[i][len(records[i])-1]))
        outp.write('\n')
