import sys
from collections import deque

t = int(input())

for i in range(t):
    p = sys.stdin.readline().rstrip()
    n = int(input())

    arr = deque(sys.stdin.readline().rstrip()[1:-1].split(","))

    okPrint = True
    revCount = 0

    if n == 0:
        arr = []

    for j in p:
        if j == 'R':
            revCount = revCount + 1
        elif j == 'D':
            if len(arr) >= 1:
                if revCount % 2 == 0:
                    arr.popleft()
                else:
                    arr.pop()
            else:
                print("error")
                okPrint = False
                break

    if okPrint == True:
        if revCount % 2 == 0:
            print("[" + ",".join(arr) + "]")
        else:
            arr.reverse()
            print("[" + ",".join(arr) + "]")