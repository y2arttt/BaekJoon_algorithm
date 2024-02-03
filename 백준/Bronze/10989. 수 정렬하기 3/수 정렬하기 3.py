import sys
from collections import deque

n = int(sys.stdin.readline())
arr = [0] * 10001
for i in range(n):
    t = int(sys.stdin.readline())
    arr[t-1] += 1

for i in range(10001):
    if arr[i] != 0:
        for _ in range(arr[i]):
            print(i+1)
        