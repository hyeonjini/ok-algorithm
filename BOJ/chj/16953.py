"""
A->B
"""

import sys

input = sys.stdin.readline

def solution(a, b):
    answer = 0

    while True:
        # 2로 나눠짐
        if b % 2 == 0:
            b //= 2
        # 끝이 1임
        else:
            if b % 10 != 1:
                return -1
            b = int(str(b)[:-1])
        answer += 1
        if a >= b:
            break
        # print(b)
    # print(a, b)
    if a != b:
        return -1
    else:
        answer += 1
    return answer

if __name__ == "__main__":
    a, b = map(int, input().split())
    print(solution(a, b))
