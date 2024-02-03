import sys
    
    
a,b,v = map(int,sys.stdin.readline().split())

v -= a
day = 1
if v % (a-b) > 0:
    day += 1
day += v // (a-b)
print(day)