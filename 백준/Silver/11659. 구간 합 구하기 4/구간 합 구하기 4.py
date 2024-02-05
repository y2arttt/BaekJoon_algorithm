import sys

result = []
n,m = map(int,sys.stdin.readline().split())
number = [0] + list(map(int,sys.stdin.readline().split()))
for i in range(2,n+1):
    number[i] += number[i-1] 
    
for _ in range(m):
    i,j = map(int,sys.stdin.readline().split())
    result.append(number[j]-number[i-1])
for i in result:
    print(i)