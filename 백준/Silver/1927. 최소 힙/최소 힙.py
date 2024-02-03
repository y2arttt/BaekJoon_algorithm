import sys

heapq = []
result = []


def insert(i):
    if i > 0 and heapq[(i-1)//2] > heapq[i]:
        heapq[(i-1)//2],heapq[i] = heapq[i],heapq[(i-1)//2]
        insert((i-1)//2)
    return

def delete(i):
    if i*2+2 < len(heapq) and heapq[i] > heapq[i*2+2] and heapq[i] > heapq[i*2+1] :
        if heapq[i*2+2] > heapq[i*2+1]:
            heapq[i*2+1],heapq[i] = heapq[i],heapq[i*2+1]
            delete(i*2+1)
        else:
            heapq[i*2+2],heapq[i] = heapq[i],heapq[i*2+2]
            delete(i*2+2)
    elif i*2+2 < len(heapq) and heapq[i] > heapq[i*2+2]:
        heapq[i*2+2],heapq[i] = heapq[i],heapq[i*2+2]   
        delete(i*2+2) 
    elif  i*2+1 < len(heapq) and heapq[i] > heapq[i*2+1]:
        heapq[i*2+1],heapq[i] = heapq[i],heapq[i*2+1]
        delete(i*2+1)
    return

n = int(sys.stdin.readline())
for _ in range(n):
    t = int(sys.stdin.readline())
    if t == 0 and heapq:
        if len(heapq) > 1:
            result.append(heapq[0])
            heapq[0] = heapq.pop(len(heapq)-1)
            delete(0)
        else:
            result.append(heapq.pop(0))
    elif t == 0:
        result.append(0)
    else:    
        heapq.append(t)
        insert(len(heapq)-1)
for i in result:
    print(i)
    