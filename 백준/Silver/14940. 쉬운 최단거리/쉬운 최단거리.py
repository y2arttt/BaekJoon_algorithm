import sys
from collections import deque

n,m = map(int,sys.stdin.readline().split())
arr = []
key = deque()
visit = [[False]*m for _ in range(n)] 

t = True
for i in range(n):
   arr.append(list(map(int,sys.stdin.readline().split())))
   if t:
    for j in range(m):
           if arr[i][j] == 2:
               key.append((i,j))
               visit[i][j] = True
               arr[i][j] = 0
               t = False
while key:
    ki,kj = key.popleft()
    if ki+1 < n and arr[ki+1][kj] != 0 and visit[ki+1][kj] == False: # 위
        arr[ki+1][kj] = arr[ki][kj] + 1
        visit[ki+1][kj] = True
        key.append((ki+1,kj))
    if 0 <= ki-1 and arr[ki-1][kj] != 0 and visit[ki-1][kj] == False: # 아래
        arr[ki-1][kj] = arr[ki][kj] + 1
        visit[ki-1][kj] = True
        key.append((ki-1,kj))
    if 0 <= kj-1 and arr[ki][kj-1] != 0 and visit[ki][kj-1] == False: # 왼쪽
        arr[ki][kj-1] = arr[ki][kj] + 1
        visit[ki][kj-1] = True
        key.append((ki,kj-1))
    if kj+1 < m and arr[ki][kj+1] != 0 and visit[ki][kj+1] == False: # 오른쪽
        arr[ki][kj+1] = arr[ki][kj] + 1
        visit[ki][kj+1] = True
        key.append((ki,kj+1))
for i in range(n):
    for j in range(m):
        if visit[i][j] == False and arr[i][j] == 1:
            print(-1,end = ' ')
        else:
            print(arr[i][j],end = ' ')
    print('')