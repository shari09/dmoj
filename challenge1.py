import sys
cin = sys.stdin.readline

n, k = list(map(int, cin().split()))
arr = list(map(int, cin().split()))

arr.sort(reverse=True)
print(sum(arr[:k]))