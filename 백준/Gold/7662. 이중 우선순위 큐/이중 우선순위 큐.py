import sys
from heapq import heappush, heappop



result = []
t = int(sys.stdin.readline())
for _ in range(t):
    heapq_min = [] # 최솟값 구하는 큐 
    heapq_max = [] # 최댓값 구하는 큐
    n = int(sys.stdin.readline())
    delete = [True] * n # 제거 확인용, 모두 없으니 True
    for id in range(n):
        t1,t2 = map(str,sys.stdin.readline().strip().split())
        t2 = int(t2)
        if t1 == 'I': # 입력받을 당시 id를 함께 입력
            heappush(heapq_min,(int(t2),id)) 
            heappush(heapq_max,(-int(t2),int(t2),id))
            delete[id] = False
        elif t2 == 1:
            while heapq_max and delete[heapq_max[0][2]]: # 이미 최솟값 힙에서 제거된 애들을 제거해줌
                heappop(heapq_max)
            if heapq_max:
                delete[heapq_max[0][2]] = True # id값에 제거됨을 저장 
                heappop(heapq_max)

        else:
            while heapq_min and delete[heapq_min[0][1]]:
                heappop(heapq_min)
            if heapq_min:
                delete[heapq_min[0][1]] = True
                heappop(heapq_min)
                
    # 연산 이후 삭제되지 않은 값 정리
    while heapq_max and delete[heapq_max[0][2]]: 
        heappop(heapq_max)            
    while heapq_min and delete[heapq_min[0][1]]:
        heappop(heapq_min)                
    if heapq_min and heapq_max:
        t1 = heappop(heapq_max)
        t2 = heappop(heapq_min)
        result.append([t1[1],t2[0]])
    else:
        result.append('EMPTY')
        
for i in result:
    if i == 'EMPTY':
        print(i)
    else:
        print(i[0],i[1])