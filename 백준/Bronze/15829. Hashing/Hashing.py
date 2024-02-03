import sys
from collections import deque

l = int(sys.stdin.readline())
string = sys.stdin.readline().rstrip()
hash = 0
for i in range(l):
    hash += (ord(string[i])-96) * (31**i) # 아스키코드 48 숫자 0, 65 대문자 A, 97 소문자 a
hash %= 1234567891
print(hash)