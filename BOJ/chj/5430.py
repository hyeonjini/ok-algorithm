"""
AC
"""
import sys
from collections import deque

input = sys.stdin.readline

def solution(commands, arr):
    q = deque(arr)
    direction = True
    for command in commands:
        if command == "R":
            # print(direction, '->', end='')
            direction = not direction 
            # print(direction)
        elif command == "D":
            if len(q) == 0:
                return 'error'
            if direction:
                q.popleft()
            else:
                q.pop()
    if direction == False:
        q.reverse()

    answer = '['+','.join(q)+']'
    return answer

if __name__ == "__main__":
    t = int(input())
    answers = []
    for tc in range(t):
        commands = list(input().rstrip())
        # print(commands)
        n = int(input())
        arr = input().rstrip()[1:-1]
        if arr != '':
            arr = list(arr.split(','))
        # print(solution(commands, arr))
        # print(arr)
        answers.append(solution(commands, arr))

    for answer in answers:
        if answer != 'error':
            print(answer)
        else:
            print(answer)