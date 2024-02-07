import sys

n = int(sys.stdin.readline())
s = set()
arr = list(map(int,sys.stdin.readline().split()))
s.update(arr)
s = list(s)
s.sort()
di = {}

for i in range(len(s)):
    di[s[i]] = i
    
for i in arr:
    print(di[i],end = ' ')


