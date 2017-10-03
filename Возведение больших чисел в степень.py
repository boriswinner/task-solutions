with open('input.txt',) as inp:
    num = inp.readline()
    pow = inp.readline()
with open('output.txt', 'w') as outp:
    outp.write(str(int(num)**int(pow)))
