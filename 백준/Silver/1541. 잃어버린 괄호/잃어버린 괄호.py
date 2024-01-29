import sys

arr = list(map(str,sys.stdin.readline().strip().split('-')))
sums = sum(map(int,arr[0].split('+')))
for i in arr[1:]:
    sums -= sum(map(int,i.split('+')))
print(sums)
