def fibonacci_rec_1(n, space):
    
    print(f"{space}-Calculando fib({n})")

    if n <= 1:
        return n

    space = "|    " + space 
    return fibonacci_rec_1(n-1, space) + fibonacci_rec_1(n-2, space)


if __name__ == "__main__":
    
    k = 16
    print(f"fib({k}) : {fibonacci_rec_1(k, "+---")}")