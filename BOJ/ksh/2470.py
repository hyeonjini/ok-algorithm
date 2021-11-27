n = int(input())
arr = sorted(list(map(int, input().split())))

start = 0
end = n-1
target = abs(arr[start]+arr[end])
myMax = 2000000001

while start < end:
    mySum = arr[start] + arr[end]
    
    if abs(mySum) < myMax:
        myMax = abs(mySum)
        minResult = arr[start]
        maxResult = arr[end]

    if mySum <= 0:
        start = start + 1
    else:
        end = end - 1

print(str(minResult) + " " + str(maxResult))