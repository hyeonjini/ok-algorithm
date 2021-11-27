"""
단어 수학
"""

import sys

input = sys.stdin.readline
max_length = 10
min_length = 1

def solution(n, words):
    answer = 0
    allocate = {}

    for word in words:
        for i in range(len(word)):
            try:
                allocate[word[i]] += 10 ** (len(word) - i)
            except:
                allocate[word[i]] = 10 ** (len(word) - i)

    # print(allocate)
    weights = sorted(allocate.items(), key = lambda x : x[1], reverse=True)
    # allocate = [(key, 9 - num) for num, (key, value) in enumerate(allocate)]
    for num, (key, value) in enumerate(weights):
        allocate[key] = 9 - num
    # print(allocate)

    for word in words:
        op = ''
        for i in range(len(word)):
            op += str(allocate[word[i]])
        # print(int(op))
        answer += int(op)
    
    return answer

if __name__ == "__main__":
    n = int(input())
    words = []

    for _ in range(n):
        words.append(input().rstrip())
    
    print(solution(n, words))