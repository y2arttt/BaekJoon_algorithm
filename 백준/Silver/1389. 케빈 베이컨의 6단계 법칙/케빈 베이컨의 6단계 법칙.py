import sys
from collections import deque


n,m = map(int,sys.stdin.readline().split())
floyd = [[1e9 for _ in range(n)] for _ in range(n)]
mins = 1e9
for _ in range(m):
    t1,t2 = map(int,sys.stdin.readline().split())
    floyd[t1-1][t2-1] = 1
    floyd[t2-1][t1-1] = 1

for i in range(n):
    for j in range(n):
        if i == j:
            floyd[i][j] = 0

for i in range(n):
    for j in range(n):
        for k in range(n):
            floyd[j][k] = min(floyd[j][k], floyd[j][i] + floyd[i][k])
t = 5000
for i in range(n):
    if mins > sum(floyd[i]):
        t = i
        mins = sum(floyd[i])
    elif mins == sum(floyd[i]):
        t = min(t,i)
print(t+1)