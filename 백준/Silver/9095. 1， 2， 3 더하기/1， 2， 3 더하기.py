import sys
from collections import deque

    
arr = []
t = int(sys.stdin.readline())
for _ in range(t):
    arr.append(int(sys.stdin.readline()))
result = [0 for _ in range(max(arr)+1)]
result[1] = 1
result[2] = 2
result[3] = 4
for i in range(4,max(arr)+1):
    result[i] = result[i-1] + result[i-2] + result[i-3]

for i in arr:
    print(result[i])
