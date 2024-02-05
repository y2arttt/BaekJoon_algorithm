import sys
sys.setrecursionlimit(10**8)

def paper(start_i,start_j,n,k=0):
    global arr,cnt_b,cnt_w
    color = arr[start_i][start_j]
    if n != 0:
        for i in range(start_i,start_i+n):
            for j in range(start_j,start_j+n):
                if arr[i][j] != color:
                    paper(start_i,start_j,n//2,1) # 1 사분면 
                    paper(start_i,(start_j+n//2),n//2,2) # 2 사분면 
                    paper((start_i+n//2),start_j,n//2,3) # 3 사분면     
                    paper((start_i+n//2),(start_j+n//2),n//2,4) # 4 사분면 
                    return
    if color == 1:
        cnt_b += 1
    else:
        cnt_w += 1  

    
arr = []
cnt_b = 0
cnt_w = 0
n = int(sys.stdin.readline())
for _ in range(n):
    arr.append(list(map(int,sys.stdin.readline().split())))
paper(0,0,n)
print(cnt_w)
print(cnt_b)
