"""
소트
"""
import sys
input = sys.stdin.readline

def solution(n, arr, s):

 
    for i in range(n):

        max_value = arr[i]
        max_index = i
        for j in range(i + 1, (i + s + 1)):
            if j >= len(arr):
                break
            if max_value < arr[j]:
                max_value = arr[j]
                max_index = j

        if max_index == i:
            continue
        # swap
        m = max_index
        while m > i:
            arr[m], arr[m-1] = arr[m-1], arr[m]
            m -= 1
        s -= (max_index - i) # 이동한 수만큼 s 감소

        # print(arr, s)

        if s == 0:
            break
        
    answer = ' '.join(list(map(str, arr)))
    return answer

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int, input().split()))
    s = int(input())
    print(solution(n, arr, s))