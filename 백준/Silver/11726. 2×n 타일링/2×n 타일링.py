import sys

n = int(sys.stdin.readline())
arr = [0 for _ in range(n)]
# 1과 2의 값 세팅
arr[0] = 1
if n > 1:
    arr[1] = 2
#규칙 = arr[n] = arr[n-2] + arr[n-1]

for i in range(2,n):
    arr[i] = arr[i-2] + arr[i-1]
    
    
print(arr[n-1]%10007)