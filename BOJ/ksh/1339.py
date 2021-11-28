n = int(input())
arr = []

for i in range(n):
    arr.append(list(map(ord,map(str, input()))))

print(arr)