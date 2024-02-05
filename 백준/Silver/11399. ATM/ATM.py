import sys
from collections import deque

    
arr = [] 
n = int(sys.stdin.readline())
p = list(map(int,sys.stdin.readline().split()))
sum = 0
sum_p = 0
p.sort()
for i in p:
    sum_p += i
    sum += sum_p
print(sum)
    