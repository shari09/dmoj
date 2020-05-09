import sys
cin = sys.stdin.readline

def cout(x):
  sys.stdout.write(str(x) + '\n')

t = int(cin())


for aaaaaa in range(t):
  n = int(cin())
  x = 0
  isWrite = []
  functions = {}

  for bbbbb in range(n):
    line = str(cin()).strip()
    if (line == 'END'):
      isWrite.pop()
    else:
      instruction, val = line.split()
      if (instruction == 'FUN'):
        isWrite.append(val)
        functions[val] = ['', 0]
      elif (len(isWrite) > 0): #inside function
        curFun = isWrite[-1]
        if (instruction == 'ADD'):
          functions[curFun] = [functions[curFun][0]+'+'+str(int(val)%1000000007)+')', functions[curFun][1]+1]
        elif (instruction == 'MULT'):
          functions[curFun] = [functions[curFun][0]+'*'+str(int(val)%1000000007)+')', functions[curFun][1]+1]
        elif (instruction == 'SUB'):
          functions[curFun] = [functions[curFun][0]+'-'+str(int(val)%1000000007)+')', functions[curFun][1]+1]
        elif (instruction == 'CALL'):
          functions[curFun] = [functions[curFun][0]+functions[val][0], functions[curFun][1]+functions[val][1]]
      else: #outside function
        if (instruction == 'ADD'):
          x += int(val)%1000000007
        elif (instruction == 'MULT'):
          x *= int(val)%1000000007
        elif (instruction == 'SUB'):
          x -= int(val)%1000000007
        elif (instruction == 'CALL'):
          x = eval('('*functions[val][1]+str(x)+functions[val][0])%1000000007
  cout(x%1000000007)
    