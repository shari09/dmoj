import sys
cin = sys.stdin.readline

def cout(x):
  sys.stdout.write(str(x) + '\n')

def findSum(num):
  total = 0
  for char in num:
    total += int(char)
  return total


q = int(cin())

for t in range(q):
  n, m = cin().split()
  maxSum = findSum(m)
  for i in range(1, len(m)):
    if (len(m) <= 1 or len(m) <= i): #no values exist
      break

    m = str(int(m[:-i])-1)+'9'*i

    if (int(m) < int(n)):
      break
    maxSum = max(maxSum, findSum(m))
  cout(maxSum)