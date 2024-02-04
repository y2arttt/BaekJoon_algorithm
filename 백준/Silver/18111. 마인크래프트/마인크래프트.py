import sys
from collections import deque


ground = []
n,m,b = map(int,sys.stdin.readline().split())

for _ in range(n):
    ground.append(list(map(int,sys.stdin.readline().split())))
time = int(1e9)
time_i = 0
for i in range(257):
    inventory = 0
    use = 0
    for x in ground:
        for xx in x:
            if xx > i:
                inventory += xx-i
            else:
                use += i-xx
    if b+inventory >= use:
        if time >= inventory*2 + use:
            time = inventory*2 + use
            time_i = i
print(time,time_i)