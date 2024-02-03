import sys
from collections import deque

n = int(sys.stdin.readline())
arr = []
if n == 0:
    print(0)
else:
    for _ in range(n):
        arr.append(int(sys.stdin.readline()))
    arr.sort()
    min = round(((len(arr)) * 0.15)+0.00000001)
    sums = sum(arr[min:len(arr)-min])
    print(round((sums/(len(arr)-(min*2))+0.00000001)))