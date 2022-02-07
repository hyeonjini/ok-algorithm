a, b = map(int, input().split())
result = 0

while True:
    if a == b:
        break

    elif a > b or b == 0:
        result = -2
        break

    elif b % 2 == 0 and b != 1:
        b = b // 2
        result = result + 1
    
    elif b % 10 == 1:
        b = b // 10
        result = result + 1

    else:
        result = -2
        break

print(result + 1)