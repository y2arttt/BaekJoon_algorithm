import sys
from collections import deque

n,m = map(int,sys.stdin.readline().split())
arr = [0 for _ in range(100)] 
check = [True for _ in range(100)] 

for _ in range(n+m):
    t1,t2 =  map(int,sys.stdin.readline().split())
    arr[t1-1] = -(t2-1)
queue = deque()


queue.append(0)  
while queue:
    t = queue.popleft()
    if t == 99:
        break
    for i in range(1,7):
        if t+i < 100 and  check[t+i] and arr[t+i] < 0 :
            if check[abs(arr[t+i])]: 
                arr[abs(arr[t+i])] = arr[t] + 1
                check[t+i] = False
                check[abs(arr[t+i])] = False
                queue.append(abs(arr[t+i]))
        elif t+i < 100 and check[t+i]:
            arr[t+i] = arr[t] + 1
            check[t+i] = False
            queue.append(t+i)
print(arr[99])

