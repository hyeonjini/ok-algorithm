"""
RGB 거리
"""
import sys
input = sys.stdin.readline

def solution(cost, n):
    answer = 0
    dp = [[0] * 3 for _ in range(n)]
    
    for k in range(3):
        dp[0][k] = cost[0][k]
        for i in range(1, n):
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0]
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1]
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2]

    # print(dp)
        
    answer = min(dp[n-1])

    return answer

if __name__ == "__main__":
    n = int(input())
    cost = []

    for _ in range(n):
        cost.append(list(map(int, input().split())))
    
    print(solution(cost, n))
