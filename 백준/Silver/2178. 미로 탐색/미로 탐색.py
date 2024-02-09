import sys
from collections import deque
n,m = map(int,sys.stdin.readline().split())
check = [[True] * m for _ in range(n)]
arr = []
queue = deque()
for i in range(n):
    t = sys.stdin.readline().rstrip()
    arr.append(list(map(int,t)))
queue.append((0,0))
while queue:
    t_i, t_j =queue.popleft()
    if t_i == n-1 and t_j == m-1:
        break
    if t_i + 1 < n and arr[t_i+1][t_j] == 1 and check: # 위
        arr[t_i+1][t_j] = arr[t_i][t_j] + 1
        check[t_i+1][t_j] = False
        queue.append((t_i+1,t_j))
    if 0 <= t_i -1 and arr[t_i-1][t_j] == 1: # 아래
        arr[t_i-1][t_j] = arr[t_i][t_j] + 1
        check[t_i-1][t_j] = False
        queue.append((t_i-1,t_j))
    if t_j + 1 < m and arr[t_i][t_j+1] == 1: # 오른쪽
        arr[t_i][t_j+1] = arr[t_i][t_j] + 1
        check[t_i][t_j+1] = False
        queue.append((t_i,t_j+1))
    if 0 <= t_j - 1  and arr[t_i][t_j-1] == 1: # 왼쪽 
        arr[t_i][t_j-1] = arr[t_i][t_j] + 1
        check[t_i][t_j-1] = False
        queue.append((t_i,t_j-1))
print(arr[n-1][m-1])