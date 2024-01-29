import sys
from collections import deque
t = int(sys.stdin.readline())
dq = deque()
result = []
for _ in range(t):
    dq.clear()
    p = sys.stdin.readline().strip()
    n = int(sys.stdin.readline())
    x = sys.stdin.readline().strip()
    x2 = x[1:len(x)-1].strip().split(',')
    revers = 0
    for i in x2:
        if i != '':
            dq.append(int(i))
    if len(dq) != n:
        result.append('error')
    elif p.count('D') > len(dq):
        result.append('error')
    else:
        for i in p:
            if i == 'R':
                revers += 1
            else:
                if revers %2 == 0:
                    dq.popleft()
                else:
                    dq.pop()
        if revers %2 == 1:
            dq.reverse()
        result.append(list(dq))

for i in result:
    if i == 'error':
        print(i)
    else:
        print("[{}]" .format( ",".join(map(str,i))))