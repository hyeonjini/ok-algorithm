"""
거짓말
"""
import sys
input = sys.stdin.readline

def find_parent(parent, x):
    if parent[x] != x:
        parent[x] = find_parent(parent, parent[x])
    return parent[x]

def union_parent(parent, a, b):
    a = find_parent(parent, a)
    b = find_parent(parent, b)

    if a < b :
        parent[b] = a
    else:
        parent[a] = b
    # parent[b] = a

def solution(n, m, know, party):
    answer = 0

    parent = [i for i in range(n + 1)] # parent 각각 자기 자신으로 초기화

    # 진실을 아는 사람 paret 0으로 초기화
    for k in know[1:]:
        parent[k] = 0
    
    for p in party:
        # print("파티 인원 수:", p[0])
        p = p[1:]
        # print(p)
        for i in range(len(p)):
            for j in range(len(p)):
                union_parent(parent, p[i], p[j])
    
        # print(parent)

    # target = set([root for root in parent if root != 0])
    # for p in party:
    #     p = set(p[1:])
        # if p.intersection(target):
        #     print(p)
        #     answer += 1
    for p in party:
        p = p[1:]
        if len(p) == 0:
            answer += 1
        for i in range(len(p)):
            if find_parent(parent, p[i]) == 0:
                break
            elif i == len(p) - 1:
                answer += 1

    return answer

if __name__ == "__main__":
    n, m = map(int, input().split()) # 사람수, 파티수
    know = list(map(int, input().split())) # 진실을 아는사람 수, 리스트
    party = []
    for _ in range(m):
        party.append(list(map(int, input().split())))

    print(solution(n, m, know, party))    



