'''
AC
'''

# 나의 풀이

import sys
from collections import deque

t = int(input())

for i in range(t):
    p = sys.stdin.readline().rstrip()
    print(p)
    n = int(input())

    arr = deque(sys.stdin.readline().rstrip().split(","))
    print(arr[1])

