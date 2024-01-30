# 알고보니 dfs였던 것에 대하여...
import sys

def dfs(i,j,sum,cnt):
    global maxc
    if cnt == 3:
        maxc = max(maxc,sum)
        return
    elif maxc >= sum + max_int * (3 - cnt): # 조기종료(모눈 종이에서 가장 큰 값을 3 -cnt번 더해도 가망이 없으면)
        return
    for y,x in direct:
        yi = i + y
        xj = j + x
        if 0<=yi < n and 0<=xj < m:
            if visit[yi][xj] == False:
                visit[yi][xj] = True # 방문한 곳 체크
                if cnt == 1: # 현 위치에서 한번 더 실행하여 ㅜ 모양을 만듦(현 위치에서 다시 실행하면 위 아래 말고는 갈 길이 없음)
                    dfs(i,j,sum + arr[yi][xj],cnt + 1)    
                dfs(yi,xj,sum + arr[yi][xj],cnt + 1)
                visit[yi][xj] = False # 백트래킹 
    return
        
direct = [(0,1),(0,-1),(1,0),(-1,0)] # 상하좌우
n,m = map(int,sys.stdin.readline().split())
arr = []
visit = [[False] * m for _ in range(n)] # 방문기록 저장용
maxc = 0 #최댓값 저장용
for i in range(n):
    arr.append(list(map(int,sys.stdin.readline().split())))
max_int = max(map(max,arr)) # 모눈종이에서 가장 큰 값 확인
for i in range(n):
    for j in range(m):
        visit[i][j] = True #체크
        dfs(i,j,arr[i][j],0)
        visit[i][j] = False #백트래킹
print(maxc)