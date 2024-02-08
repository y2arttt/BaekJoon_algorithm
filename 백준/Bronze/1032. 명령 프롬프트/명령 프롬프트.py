import sys
n = int(sys.stdin.readline())
arr = sys.stdin.readline().rstrip()
for _ in range(n-1):
    t = sys.stdin.readline().rstrip()
    for i in range(len(t)):
        if arr[i] != t[i]:
            arr = list(arr)
            arr[i] = '?'
            k = "".join(arr)
            arr = k
print(arr)