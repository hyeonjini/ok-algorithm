"""
경로 찾기
"""
import sys
input = sys.stdin.readline

def solution(n, graph):
    for k in range(n):
        for a in range(n):
            for b in range(n):
                if graph[a][k] + graph[k][b] > 1:
                    graph[a][b] = 1

    for i in range(n):
        for j in range(n):
            print(graph[i][j], end=" ")
        print()

if __name__ == "__main__":
    n = int(input())
    graph = [[0] * n for _ in range(n)]

    for i in range(n):
        data = list(map(int, input().split()))
        for j in range(len(data)):
            if data[j] == 1:
                graph[i][j] = 1
        
    solution(n, graph)
