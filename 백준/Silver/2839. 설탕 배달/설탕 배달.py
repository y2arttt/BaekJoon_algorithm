import sys
    
    
n = int(sys.stdin.readline()) 
if n <= 5: #5까지는 계산하여 못 구함(직접 계산해야됨)
    if n - 3 == 0 or n - 5== 0:
          print(1)
    else: print(-1)
else:
    minc = [5001 for _ in range(n+1)] # 값 까지의 최소 cnt 저장
    minc[3] = 1 
    minc[5] = 1 
    for i in range(6,n+1): # (1,2,4) 못만듦, (3,5) 1로 계산 완료
        minc[i] = min(minc[i-3],minc[i-5]) + 1  #기존에 계산값을 활용하여 최소 cnt 구하기
    if minc[n] >= 5001: print(-1)
    else: print(minc[n])