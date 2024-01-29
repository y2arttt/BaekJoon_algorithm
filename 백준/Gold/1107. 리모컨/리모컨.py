import sys



def number(s):
    global min_c,n
    for i in st:
        tmp = str(s) + str(i)
        t = abs(n - int(tmp)) + len(tmp) 
        min_c = min(min_c,t)
        if len(tmp) < 6:
            number(tmp) 

n= int(sys.stdin.readline())
m = int(sys.stdin.readline())
st = {i for i in range(10)}
if m > 0: st -= set(map(int,sys.stdin.readline().split()))
min_c = abs(100 - n)

if m < 10: number('')
print(min_c)
