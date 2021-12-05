from collections import deque

A, B = map(int, input().split())

dq = deque()
result = -1
dq.append((A, 1))
while dq:
    value, depth = dq.popleft()
    if value == B:
        result = depth
        break
    if value * 2 <= B:
        dq.append((value * 2, depth + 1))
    if int(str(value) + "1") <= B:
        dq.append((int(str(value) + "1"), depth + 1))

print(result)