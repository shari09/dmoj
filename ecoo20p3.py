import sys, math
cin = sys.stdin.readline

cout = sys.stdout.write


def topLeft(captcha, h, w):
  for i in range(math.floor(h/2)):
    if (captcha[i].find('*', 0, w/2)):
      return True
  return False

def topRight(captcha, h, w):
  for i in range(math.floor(h/2)):
    if (captcha[i].find('*', w/2)):
      return True
  return False

def middle(captcha, h):
  if (h%2 == 0):
    return False
  elif ('*' in captcha[h/2]):
    return True
  return False

def bottomLeft(captcha, h, w):
  for i in range(math.ceil(h/2), h):
    if (captcha[i].find('*', 0, w/2)):
      return True
  return False

def bottomRight(captcha, h, w):
  for i in range(math.ceil(h/2), h):
    if (captcha[i].find('*', w/2)):
      return True
  return False

def topLine(captcha, h, w):
  

t = int(cin())
for _ in range(t):
  n = int(cin())
  for ijijiji in range(n):
    h, w = map(int, cin().split())
    captcha = []
    for alksdjf in range(h):
      captcha.append(cin().strip())
      if (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('0')
      elif (
        not topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and not bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
      elif (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
      elif (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
      elif (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
      elif (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
      elif (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
      elif (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
      elif (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
      elif (
        topLeft(captcha, h, w)
        and topRight(captcha, h, w)
        and not middle(captcha, h, w)
        and bottomLeft(captcha, h, w)
        and bottomRight(captcha, h, w)
      ):
        cout('1')
  cout('\n')