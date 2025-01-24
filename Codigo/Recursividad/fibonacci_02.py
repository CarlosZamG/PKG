def fibonacci_rec_2(n, num1, num2):

    if n == 0:
        return num1

    return fibonacci_rec_2(n-1, num2, num1 + num2)


if __name__ == "__main__":
    
    k = 100
    for i in range(k+1):
        print(f"fib({i}) : {fibonacci_rec_2(i, 0, 1)}")