import sys
from collections import deque

m,n = map(int,sys.stdin.readline().split())
arr = []
max = 1
cnt = 0
for i in range(n):
    arr.append(list(map(int,sys.stdin.readline().split())))
dq = deque()
for i in range(n):
    for j in range(m):
        if arr[i][j] == 1:
            dq.append([i,j])
        if arr[i][j] == -1:
            cnt += 1

while dq:
        tmp = dq.popleft()
        cnt +=1
        if tmp[0]+1 < n and arr[tmp[0]+1][tmp[1]] == 0: # 아래
            arr[tmp[0]+1][tmp[1]] = arr[tmp[0]][tmp[1]] + 1
            dq.append([tmp[0]+1,tmp[1]])
            if max < arr[tmp[0]][tmp[1]] + 1:
                max = arr[tmp[0]][tmp[1]] + 1
        if 0 <= tmp[0]-1 and arr[tmp[0]-1][tmp[1]] == 0: # 위
            arr[tmp[0]-1][tmp[1]] = arr[tmp[0]][tmp[1]] + 1
            dq.append([tmp[0]-1,tmp[1]])
            if max < arr[tmp[0]][tmp[1]] + 1:
                max = arr[tmp[0]][tmp[1]] + 1
        if tmp[1]+1 < m  and arr[tmp[0]][tmp[1]+1] == 0: # 오른쪽
            arr[tmp[0]][tmp[1]+1] = arr[tmp[0]][tmp[1]] + 1
            dq.append([tmp[0],tmp[1]+1])
            if max < arr[tmp[0]][tmp[1]] + 1:
                max = arr[tmp[0]][tmp[1]] + 1
        if 0 <= tmp[1]-1 and arr[tmp[0]][tmp[1]-1] == 0: # 왼쪽
            arr[tmp[0]][tmp[1]-1] = arr[tmp[0]][tmp[1]] + 1
            dq.append([tmp[0],tmp[1]-1])
            if max < arr[tmp[0]][tmp[1]] + 1:
                max = arr[tmp[0]][tmp[1]] + 1
if n*m - cnt == 0:
    print(max-1)
else:
    print(-1)