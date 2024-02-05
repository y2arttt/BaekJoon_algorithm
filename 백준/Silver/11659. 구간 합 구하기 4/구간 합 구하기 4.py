import sys

result = []
n,m = map(int,sys.stdin.readline().split())
number = [0] + list(map(int,sys.stdin.readline().split()))
for i in range(2,n+1):
    number[i] += number[i-1] # 순서대로 누적 합 구하기
    
for _ in range(m):
    i,j = map(int,sys.stdin.readline().split())
    result.append(number[j]-number[i-1]) # 구간만 남기고 나머지 값을 누적 값에서 빼버림
for i in result:
    print(i)