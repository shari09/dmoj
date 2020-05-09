import sys
cin = sys.stdin.readline

def cout(x):
  sys.stdout.write(str(x) + '\n')

cordsDic = {
  'C': 1,
  'C#': 2,
  'D': 3,
  'D#': 4,
  'E': 5,
  'F': 6,
  'F#': 7,
  'G': 8,
  'G#': 9,
  'A': 10,
  'A#': 11,
  'B': 12
}

def isApart(a, b, num):
  if (cordsDic[b] - cordsDic[a] == num):
    return True
  elif (cordsDic[b]+12 - cordsDic[a] == num):
    return True
  return False

def isDominant(a, b, c, d):
  if (isApart(a, b, 4) and isApart(b, c, 3) and isApart(c, d, 3)):
    return True
  return False


t = int(cin())

for q in range(t):
  a, b, c, d = cin().split()
  if (isDominant(a, b, c, d)):
    cout('root')
  elif (isDominant(d, a, b, c)):
    cout('first')
  elif (isDominant(c, d, a, b)):
    cout('second')
  elif (isDominant(b, c, d, a)):
    cout('third')
  else:
    cout('invalid')