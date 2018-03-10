import string
from operator import itemgetter
import re
import copy

ASCII_OFFSET = 97

class Polynom():
    monoms = []

    def optimize(self):
        i = 0
        j = 1
        while i < len(self.monoms):
            while j < len(self.monoms):
                monomssHaveSameVariables = True
                k = 0
                for cnt in range(len(string.ascii_lowercase)):
                    if (self.monoms[i]['monoms'][cnt] == self.monoms[j]['monoms'][cnt]):
                        k += 1
                if k != len(string.ascii_lowercase):
                    i = j - 1
                    monomssHaveSameVariables = False
                    break
                if monomssHaveSameVariables:
                    self.monoms[i]['coefficient'] += self.monoms[j]['coefficient']
                    self.monoms[j]['coefficient'] = 0
                j += 1
            i += 1
            j = i + 1

    def __init__(self, letter = None):
        if letter is not None:
            dict ={
                'coefficient': 1,
                'monoms': [int(1) if ord(letter) - ASCII_OFFSET == i else int(0)
                          for i in range(len(string.ascii_lowercase))]}
            self.monoms = [dict]

    def __add__(self, other):
        res = Polynom()
        res.monoms = [copy.deepcopy(i) for i in self.monoms + other.monoms]
        return res

    def __sub__(self, other):
        res = Polynom()
        temp = [{'coefficient': -i['coefficient'], 'monoms': i['monoms']} for i in other.monoms]
        res.monoms = [i.copy() for i in self.monoms] + temp
        return res

    def __mul__(self, other):
        res = Polynom()
        t1 = copy.deepcopy(self.monoms)
        t2 = copy.deepcopy(other.monoms)
        t3 = []

        for i in range(len(t1)):
            for j in range(len(t2)):
                t3.append([])
                for z in range(len(t1[i]['monoms'])):
                    t3[len(t3) - 1].append(t1[i]['monoms'][z] + t2[j]['monoms'][z])
                t3[len(t3) - 1] = {'coefficient':t1[i]['coefficient'] * t2[j]['coefficient'], 'monoms':t3[len(t3) - 1]}
        res.monoms = t3
        return res

    def __neg__(self):
        res = Polynom()
        res.monoms = [{'coefficient': -i['coefficient'], 'monoms': i['monoms']} for i in self.monoms]
        return res

    def __str__(self):
        res = ''
        for i in range(len(self.monoms)):
            if (self.monoms[i] is None):
                continue
            if (int(self.monoms[i]['coefficient'] == 0)):
                continue
            hasCoeff = False
            if (i > 0) and (int(self.monoms[i]['coefficient']) > 0):
                res += '+'
            if (int(self.monoms[i]['coefficient']) != 1 and int(self.monoms[i]['coefficient']) != -1):
                res += str(self.monoms[i]['coefficient'])
                hasCoeff = True
            elif (int(self.monoms[i]['coefficient'] == -1)):
                res += '-'
            first = True
            if (hasCoeff):
                res += '*'
            for j in range(len(self.monoms[i]['monoms'])):
                if (int(self.monoms[i]['monoms'][j]) > 0) and (not first):
                    res += '*'
                if (int(self.monoms[i]['monoms'][j]) > 0):
                    res += chr(int(j) + ASCII_OFFSET)
                    first = False
                if (int(self.monoms[i]['monoms'][j]) > 1):
                    res += '^' + str(self.monoms[i]['monoms'][j])
        if (res == ''):
            res += '0'
        return res


with open("input.txt") as cin:
    sin = cin.read()
    sin = re.sub(r'[a-z]', 'allowedVariables[\'' + '\g<0>' + '\']', sin)
    allowedVariables = {}
    for i in list(string.ascii_lowercase):
        exec ("allowedVariables[\'%s\'] = Polynom(\'%s\')" % (i, i))
    res = eval(sin)
    res.monoms.sort(key=itemgetter('monoms'))
    res.optimize()
with open('output.txt', 'w') as cout:
    cout.write(str(res))
