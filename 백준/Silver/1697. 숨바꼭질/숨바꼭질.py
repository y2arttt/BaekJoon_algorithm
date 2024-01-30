import sys
from collections import deque
n,k = map(int,sys.stdin.readline().split())
cnt = [0 for _ in range(100001)]
queue = deque()
queue.append(n)
visit = [False] * 100001
visit[n] = True
while True:
    x = queue.popleft()
    if x == k:
        break
    if x+1 <= 100000 and visit[x+1] == False:
        visit[x+1] = True
        cnt[x+1] = cnt[x]+1
        queue.append(x+1)
    if 0 <= x-1 and visit[x-1] == False:
        visit[x-1] = True
        cnt[x-1] = cnt[x]+1
        queue.append(x-1)
    if 2*x <= 100000 and visit[2*x] == False:
        visit[2*x] = True
        cnt[2*x] = cnt[x]+1
        queue.append(2*x)
print(cnt[x])