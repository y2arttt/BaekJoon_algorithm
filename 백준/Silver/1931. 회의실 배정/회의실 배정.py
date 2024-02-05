import sys

arr = []
n = int(sys.stdin.readline())
cnt = 1
for _ in range(n):
    arr.append(tuple(map(int,sys.stdin.readline().split())))
#핵심: 끝나는 시간이 가장 빠른 순으로 회의하기
arr.sort(key = lambda x: (x[1],x[0])) #끝나는 시간이 같을 경우 시작 시간이 빠른 순으로 정렬
i = 0
for j in range(1,n):
    if arr[i][1] <= arr[j][0]: #끝난 시간보다 시작시간이 큰 가장 빠른 끝나는 시간 구하기
        cnt += 1
        i = j
print(cnt)
            
        

