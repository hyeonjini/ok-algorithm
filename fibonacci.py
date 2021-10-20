def fibonacci(n):
    if n <= 1:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)


def fibonacci_iterative(n):
    fibo = [0] * (n + 1)
    if n > 0:
        fibo[1] = 1
        for i in range(2, n + 1):
            fibo[i] = fibo[i - 2] + fibo[i - 1]

    return fibo[n]


def fibonacci_iterative_space(n):
    if n < 2:
        return n
    else:
        temp0 = 0
        temp1 = 1
        result = 0

        for i in range(1, n):
            result = temp0 + temp1
            temp0, temp1 = temp1, result
        return result


if __name__ == '__main__':

    for i in range(11):
        print(fibonacci_iterative_space(i), end=" ")
