"""
두 용액
"""
import sys
input = sys.stdin.readline

def solution(arr):
    a, b = 0, 0
    arr.sort()
    left, right = 0, len(arr) -1
    # print(arr)

    target = int(1e9)
    while left < right:
        
        summation = arr[left] + arr[right]
        summation_left = arr[left + 1] + arr[right]
        summation_right = arr[left] + arr[right-1]
        # print('current', arr[left], arr[right], summation)

        if abs(0 - summation) < abs(target): # 0 과의 차이가 더 작다면
            target = summation
            a = arr[left]
            b = arr[right]

        if abs(0 - summation_left) < abs(0 - summation_right):
            # print('left')
            left += 1
        else:
            # print('right')
            right -= 1

        
    return a, b

if __name__ == "__main__":
    n = int(input())
    arr = list(map(int , input().split()))
    a, b = solution(arr)
    print(a, b)
