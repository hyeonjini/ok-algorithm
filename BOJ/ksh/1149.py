n = int(input())
arr = []

for i in range(n):
    arr.append(list(map(int,input().split())))

'''
arr[i][0] = R
arr[i][1] = G
arr[i][2] = B
'''
for i in range(1, n):
    arr[i][0] = min(arr[i-1][1], arr[i-1][2]) + arr[i][0]
    arr[i][1] = min(arr[i-1][0], arr[i-1][2]) + arr[i][1]
    arr[i][2] = min(arr[i-1][0], arr[i-1][1]) + arr[i][2]

print(str(min(arr[n-1][0], arr[n-1][1], arr[n-1][2])))
print(arr[n-1][0], arr[n-1][1], arr[n-1][2])