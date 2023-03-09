def fib_memoization(n, cache={}):
    if n < 2:
        return n

    if n in cache:
        return cache[n]

    cache[n] = fib_memoization(n - 1, cache) + fib_memoization(n - 2, cache)
    return cache[n]


def minimum_sum_subarray(array):
    min_element = min(array)

    for i in range(len(array)):
        for j in range(i + 1, len(array)):
            if len(array[i : j + 1]) == 0:
                continue

            # print(array[i : j + 1])

            suma = sum(array[i : j + 1])
            if suma < min_element:
                min_element = suma

    return min_element


def min_sum_dynamic(array):
    if len(array) == 0:
        return 0

    min_sum_element = array[0]
    min_sum = array[0]

    for i in range(1, len(array)):
        number = array[i]
        current_min = min(number, number + min_sum_element[i - 1])
        min_sum_element = current_min
        min_sum = min(min_sum, current_min)

    return min_sum


array = [-7, 3, 4, -2, -3, 1, -3]
print(minimum_sum_subarray(array))
