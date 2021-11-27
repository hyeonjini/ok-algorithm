"""
두 용액
"""
import sys
input = sys.stdin.readline

def solution(arr, n):
    a, b = 0, 0
    arr.sort()
    left, right = 0, n - 1
    # print(arr)

    min_abs = int(2e9)
    while left < right:
        
        summation = arr[left] + arr[right]

        if abs(summation) < min_abs: # 0 과의 차이가 더 작다면
            min_abs = abs(summation)
            a = arr[left]
            b = arr[right]
            if summation == 0:
                break

        if summation < 0:
            # print('left')
            left += 1
        else:
            # print('right')
            right -= 1

    return a, b

if __name__ == "__main__":
    n = int(input())    
    arr = list(map(int , input().split()))
    a, b = solution(arr, n)
    print(a, b)
