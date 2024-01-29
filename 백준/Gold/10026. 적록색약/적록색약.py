import sys
from collections import deque

cnt = {'R':0,'G':0,'B':0,'RG':0}
n = int(sys.stdin.readline())
arr = []
ing = []
queue = deque()
for _ in range(n):
    arr.append(str(sys.stdin.readline().strip()))
m = []
for _ in range(n):
    m.append([0 for i in range(n)])

for i in range(n):
    for j in range(n):
        if m[i][j] == 0:
            cnt[arr[i][j]] += 1
            queue.clear()
            queue.append([i,j])
            while queue:
                ing = list(queue.popleft())
                if 0 < ing[0] and m[ing[0]-1][ing[1]] == 0 and arr[ing[0]-1][ing[1]] == arr[i][j]: #위
                    m[ing[0]-1][ing[1]] = 1
                    queue.append([ing[0]-1,ing[1]])
                if ing[0] < n-1 and m[ing[0]+1][ing[1]] == 0 and arr[ing[0]+1][ing[1]] == arr[i][j]: #아래
                    m[ing[0]+1][ing[1]] = 1
                    queue.append([ing[0]+1,ing[1]])
                if ing[1] < n-1 and m[ing[0]][ing[1]+1] == 0 and arr[ing[0]][ing[1]+1] == arr[i][j]: #오른쪽
                    m[ing[0]][ing[1]+1] = 1
                    queue.append([ing[0],ing[1]+1])
                if 0 < ing[1] and m[ing[0]][ing[1]-1] == 0 and arr[ing[0]][ing[1]-1] == arr[i][j]: #왼쪽
                    m[ing[0]][ing[1]-1] = 1
                    queue.append([ing[0],ing[1]-1])

m2 = []
for _ in range(n):
    m2.append([0 for i in range(n)])
for i in range(n):
    for j in range(n):
        if m2[i][j] == 0 and arr[i][j] != 'B':
            cnt['RG'] += 1
            queue.clear()
            queue.append([i,j])
            while queue:
                ing = list(queue.popleft())
                if 0 < ing[0] and m2[ing[0]-1][ing[1]] == 0 and arr[ing[0]-1][ing[1]] != 'B': #위
                    m2[ing[0]-1][ing[1]] = 1
                    queue.append([ing[0]-1,ing[1]])
                if ing[0] < n-1 and m2[ing[0]+1][ing[1]] == 0 and arr[ing[0]+1][ing[1]] != 'B': #아래
                    m2[ing[0]+1][ing[1]] = 1
                    queue.append([ing[0]+1,ing[1]])
                if ing[1] < n-1 and m2[ing[0]][ing[1]+1] == 0 and arr[ing[0]][ing[1]+1] != 'B': #오른쪽
                    m2[ing[0]][ing[1]+1] = 1
                    queue.append([ing[0],ing[1]+1])
                if 0 < ing[1] and m2[ing[0]][ing[1]-1] == 0 and arr[ing[0]][ing[1]-1] != 'B': #왼쪽
                    m2[ing[0]][ing[1]-1] = 1
                    queue.append([ing[0],ing[1]-1])
print(cnt['R']+cnt['G']+cnt['B'],cnt['RG']+cnt['B'])
            