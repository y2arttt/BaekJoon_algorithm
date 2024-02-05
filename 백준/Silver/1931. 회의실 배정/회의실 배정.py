import sys



arr = []
n = int(sys.stdin.readline())
cnt = 1
for _ in range(n):
    arr.append(tuple(map(int,sys.stdin.readline().split())))
arr.sort(key = lambda x: (x[1],x[0]))
i = 0
for j in range(1,n):
    if arr[i][1] <= arr[j][0]:
        cnt += 1
        i = j
print(cnt)
            