import sys
from collections import deque

n,m = map(int,sys.stdin.readline().split())
arr = [0 for _ in range(100)] # 게임 판
check = [True for _ in range(100)] #판 방문여부

for _ in range(n+m): #사다리&뱀 입력
    t1,t2 =  map(int,sys.stdin.readline().split())
    arr[t1-1] = -(t2-1)
queue = deque()

queue.append(0)  
while True:
    t = queue.popleft()
    if t == 99: #판 끝에 도착하면 예외
        break
    for i in range(1,7): # 주사위 던지기
        if t+i < 100 and  check[t+i] and arr[t+i] < 0 : #도착한 곳에 사다리&뱀 있는지 여부 확인 + 주사위가 판 넘지 않았는지 확인
            if check[abs(arr[t+i])]: # 사다리&뱀이 있으면 무조건 이동해야하는데, 굳이 최단거리가 아니면 확인할 필요가 없으므로
                arr[abs(arr[t+i])] = arr[t] + 1
                check[t+i] = False
                check[abs(arr[t+i])] = False # **이동 후 방문 확인해주기**
                queue.append(abs(arr[t+i]))
        elif t+i < 100 and check[t+i]:
            arr[t+i] = arr[t] + 1
            check[t+i] = False
            queue.append(t+i)
print(arr[99])
