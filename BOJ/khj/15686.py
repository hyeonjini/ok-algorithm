import sys
from itertools import combinations

N, M = list(map(int, input().split()))

city = [list(map(int, input().split())) for _ in range(N)]

house = []
chicken = []

for i in range(N):
    for j in range(N):
        if city[i][j] == 1:
            house.append((i, j))
        elif city[i][j] == 2:
            chicken.append((i, j))

chicken_open = combinations(chicken, M)

result = []

for i in chicken_open:
    _sum = 0
    for j in house:
        dist = sys.maxsize
        for k in i:
            if abs(j[0] - k[0]) + abs(j[1] - k[1]) < dist:
                dist = abs(j[0] - k[0]) + abs(j[1] - k[1])
        _sum += dist

    result.append(_sum)

result.sort()

print(result[0])

