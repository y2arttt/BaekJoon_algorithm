import sys
n,m = map(int,sys.stdin.readline().split())
poketmon = {}
dic = {}
for i in range(1,n+1):
    name = sys.stdin.readline().strip()
    poketmon.update({name:i})
    dic.update({i:name})

for _ in range(m):
    question = sys.stdin.readline().strip()
    if 48 <= ord(question[0]) <=57:
        print(dic[int(question)])
    else:
        print(poketmon[question])