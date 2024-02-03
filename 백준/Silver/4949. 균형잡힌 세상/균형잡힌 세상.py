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
        for i in st: #핵심: 괄호를 닫을때 여는 괄호와 쌍으로 지움
            if i == '(' or i == '[':
                stack.append(i) #스택에 여는 문장을 추가
            elif i == ')' or i == ']':
                if len(stack) > 0:
                    t1 = stack.pop()
                    if t1 == '(' and i == ')':
                        continue
                    elif t1 == '[' and i == ']':
                        continue
                stack.append(-1) # 괄호가 제대로 끝마쳐지지 않으면 스택을 비우지 않음
                break
            elif i == '.' : 
               break
        if stack: #스택이 있음: 마지막이 끝맺어지지 않음 or -1
            result.append("no")   
        else:
            result.append("yes")
for i in result:
    print(i)