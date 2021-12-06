import sys
import heapq

INF = int(1e9)

input = sys.stdin.readline

V, E = map(int, input().split())
K = int(input()) # start vertex

graph = [[] for _ in range(V + 1)]
distance = [INF] * (V + 1)

for _ in range(E):
    u, v, w = map(int , input().split())
    graph[u].append((v, w))

def dijkstra(start):

    q = []
    heapq.heappush(q, (0, start))
    distance[start] = 0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now] < dist:
            continue

        for j in graph[now]:
            # j[0]: vertex, j[1]: weight
            cost = j[1] + dist
            if cost < distance[j[0]]:
                distance[j[0]] = cost
                heapq.heappush(q, (cost, j[0]))

dijkstra(K)

for dist in distance[1:]:
    print(dist if dist < INF else "INF")