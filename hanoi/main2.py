def hanoi(n, a, b, c):
    count = 0
    if n == 1:
        count += 1
    else:
        count += hanoi(n - 1, a, c, b)
        count += hanoi(1, a, b, c)
        count += hanoi(n - 1, b, a, c)
    return count


print(hanoi(4, 'a', 'b', 'c'))
