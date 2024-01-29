import sys
from collections import deque

def dfs(v):
    global visit
    print(v+1,end = ' ')
    for i in range(n):
        if (arr[v][i] == 1 or arr[i][v] == 1) and visit[i] == 0:
            arr[v][i] = 0
            arr[i][v] = 0
            visit[i] = 1
            dfs(i)

def bfs(v):
    global visit
    t = v
    dq.append(t)
    while dq:
        t = dq.popleft()
        if visit[t] == 0:
            print(t+1,end = ' ')
            visit[t] = 1
        for i in range(n):
            if arr[t][i] == 1 or arr[i][t] == 1:
                arr[t][i] = 0
                arr[i][t] = 0
                dq.append(i)
          
dq = deque()    
n,m,v = map(int,sys.stdin.readline().split())
arr = [[0 for _ in range(n)] for _ in range(n)]
tmp = []
for i in range(m):
    tmp.append(list(map(int,sys.stdin.readline().split())))
    arr[tmp[i][0]-1][tmp[i][1]-1] = 1
    
visit = [0 for _ in range(n)]
visit[v-1] = 1
dfs(v-1)
print('')
arr = [[0 for _ in range(n)] for _ in range(n)]
for i in range(m):
    arr[tmp[i][0]-1][tmp[i][1]-1] = 1
visit = [0 for _ in range(n)]

bfs(v-1)