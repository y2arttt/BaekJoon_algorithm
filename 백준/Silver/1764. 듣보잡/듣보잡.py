import sys
from collections import deque
name = {}
듣보잡 = []
n,m = map(int,sys.stdin.readline().split())
for _ in range(n):
    name[sys.stdin.readline().strip()] = 1
for _ in range(m):
    t = sys.stdin.readline().strip()
    if t in name.keys():
        듣보잡.append(t)
듣보잡.sort()
print(len(듣보잡))
for i in 듣보잡:
    print(i)