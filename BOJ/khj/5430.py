import ast


def result_of(command, array):
    if command == "R":
        array.reverse() # O(n)
    elif command == "D":
        array.pop(0) # O(1)


n = int(input())
for _ in range(n):
    error = False

    commands = input()
    size = int(input())
    array = ast.literal_eval(input())

    for command in list(commands):
        if len(array) == 0:
            error = True
            break
        result_of(command, array)
    print(array if not error else "error")

# array = [1,2,3,4,5]
# result_of("D", array)
# print(array)
