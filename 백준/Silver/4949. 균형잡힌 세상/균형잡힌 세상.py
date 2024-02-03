import sys
from collections import deque

result = []
stack = deque()

while True:   
    st = sys.stdin.readline().rstrip()
    stack.clear()
    if st[0] == '.':
        break
    else:
        for i in st:
            if i == '(' or i == '[':
                stack.append(i)
            elif i == ')' or i == ']':
                if len(stack) > 0:
                    t1 = stack.pop()
                    if t1 == '(' and i == ')':
                        continue
                    elif t1 == '[' and i == ']':
                        continue
                stack.append(-1)          
            elif i == '.' :
               break
        if stack:
            result.append("no")   
        else:
            result.append("yes")
for i in result:
    print(i)