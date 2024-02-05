import sys

s = set()
n = int(sys.stdin.readline())
for _  in range(n):
    t = sys.stdin.readline().rstrip().split()
    if t[0] == 'all':
        s = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20}
    elif t[0] == 'add':
        s.add(int(t[1]))
    elif t[0] == 'remove':
        if int(t[1]) in s: s.remove(int(t[1]))
    elif t[0] == 'check':
        if int(t[1]) in s: print(1)
        else: print(0)
    elif t[0] == 'toggle':
        if int(t[1]) in s: s.remove(int(t[1]))
        else: s.add(int(t[1]))
    else:
        s = set()
