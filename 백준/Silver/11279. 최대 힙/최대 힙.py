import sys


def insert(i):
    if 0 < i and heapq[(i-1)//2] < heapq[i]:
        heapq[i],heapq[(i-1)//2] = heapq[(i-1)//2],heapq[i]
        insert((i-1)//2)
    return

def delete(i):
    if i*2+2 < len(heapq) and heapq[i] < heapq[i*2+1] and heapq[i] < heapq[i*2+2]:
        if heapq[i*2+1] < heapq[i*2+2]:
            heapq[i],heapq[i*2+2] = heapq[i*2+2],heapq[i]
            delete(i*2+2)
        else:
            heapq[i],heapq[i*2+1] = heapq[i*2+1],heapq[i]
            delete(i*2+1)
    elif i*2+1 < len(heapq) and heapq[i] < heapq[i*2+1]:
        heapq[i],heapq[i*2+1] =  heapq[i*2+1], heapq[i]
        delete(i*2+1)
    elif i*2+2 < len(heapq) and heapq[i] < heapq[i*2+2]:
        heapq[i],heapq[i*2+2] = heapq[i*2+2],heapq[i]
        delete(i*2+2)
    return

result = []
heapq = []
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