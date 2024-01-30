import sys
from collections import deque
n,k = map(int,sys.stdin.readline().split())
cnt = [0 for _ in range(100001)] # 0~100000의 1차원 좌표
queue = deque()
queue.append(n)
visit = [False] * 100001 # 중복 방문 방지(어차피 제일 첫 방문이 제일 빨리 도착한거임)
visit[n] = True
while True: #bfs 활용
    x = queue.popleft()
    if x == k: #도착시 멈춤
        break
    if x+1 <= 100000 and visit[x+1] == False: # 좌표를 넘을 시 진행 X
        visit[x+1] = True # 방문 체크
        cnt[x+1] = cnt[x]+1 # 현재 좌표 카운트 + 1
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