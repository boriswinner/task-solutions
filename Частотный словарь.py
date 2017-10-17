import re, collections
inarr = re.findall(r'\w+', open('input.txt').read().lower())
dict = collections.Counter(inarr)
with open('output.txt', 'w') as cout:
    for i in sorted(dict):
        cout.write(str(i) + ' ' + str(dict[i]) + '\n')
