import sys
from collections import deque

n = int(sys.stdin.readline())
arr = []
for i in range(n):
    arr.append(tuple(map(int,sys.stdin.readline().split())))
    
arr.sort(key = lambda x: (x[1],x[0]))
for i in arr:
    for j in i:
        print(j,end = ' ')
    print()