import sys
def game(i,j):  
    global tetris,arr
    maxd = 0
    for x in tetris:
        sum = 0
        for a,b in x:
            ai = i + a
            bj = j + b
            if ai < n and bj < m:
                sum += arr[ai][bj]
        maxd = max(maxd,sum)
    return maxd
    
tetris=[[(0,0),(0,1),(0,2),(0,3)],\
        [(0,0),(1,0),(2,0),(3,0)],\
        [(0,0),(1,0),(0,1),(1,1)],\
        [(0,0),(1,0),(2,0),(2,1)],\
        [(0,1),(1,1),(2,1),(2,0)],\
        [(0,0),(0,1),(1,1),(2,1)],\
        [(0,0),(0,1),(1,0),(2,0)],\
        [(0,0),(1,0),(1,1),(1,2)],\
        [(0,2),(1,1),(1,2),(1,0)],\
        [(0,0),(0,1),(0,2),(1,2)],\
        [(0,0),(1,0),(0,1),(0,2)],\
        [(0,0),(1,0),(1,1),(2,1)],\
        [(0,1),(1,1),(1,0),(2,0)],\
        [(1,0),(1,1),(0,1),(0,2)],\
        [(0,0),(0,1),(1,1),(1,2)],\
        [(0,1),(1,0),(1,1),(1,2)],\
        [(0,0),(0,1),(0,2),(1,1)],\
        [(0,0),(1,0),(1,1),(2,0)],\
        [(0,1),(1,1),(1,0),(2,1)]]

n,m = map(int,sys.stdin.readline().split())
arr = []
maxc = 0
for _ in range(n):
    arr.append(list(map(int,sys.stdin.readline().split())))

for i in range(n):
    for j in range(m):
        maxc = max(maxc,game(i,j)) 
print(maxc)