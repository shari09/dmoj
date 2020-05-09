import sys
cin = sys.stdin.readline

for t in range(10):
  numRule, numItr, axiom = cin().split()
  numRule, numItr = int(numRule), int(numItr)

  ruleDict = {}
  countList = [0]*26
  newList = countList[:]

  for i in range(numRule):
    char, string = cin().split()
    ruleDict[char] = list(string)

  for c in axiom:
    countList[ord(c)-65] += 1

  beg,end = axiom[0], axiom[-1]

  for i in range(numItr):
    beg = ruleDict[beg][0]
    end = ruleDict[end][-1]
    newList = countList[:]
    for j in range(len(countList)):
      if countList[j] > 0:
        num = countList[j]
        replacement = ruleDict[chr(j+65)]
        for letter in replacement:
          newList[ord(letter)-65] += num
        newList[j] -= num
    countList = newList[:]

  print(beg+end, sum(countList))