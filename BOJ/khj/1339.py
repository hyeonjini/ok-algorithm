# string to int 함수
def string_to_int(n):
    result = []
    for i in list(n):
        if "A" == i:
            result.append("9")
        elif "B" == i:
            result.append("4")
        elif "C" == i:
            result.append("8")
        elif "D" == i:
            result.append("6")
        elif "E" == i:
            result.append("5")
        elif "F" == i:
            result.append("3")
        elif "G" == i:
            result.append("7")

    return int("".join(result))

n = int(input())
result = 0
for _ in range(n):
    result += string_to_int(input())

print(result)