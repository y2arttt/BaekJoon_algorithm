import sys
n = list(map(int,sys.stdin.readline().split()))
num = 1
while True:
    t = 0
    for i in n:
        if num % i == 0:
            t+= 1
    if t >= 3:
        print(num)
        break
    num+=1

