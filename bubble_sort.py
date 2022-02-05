def bubble_sort(array: list) -> list:
    swap = False
    for i in range(0, len(array) - 1):
        for j in range(0, len(array) - 1 - i):
            if array[j] > array[j + 1]:
                array[j], array[j + 1] = array[j + 1], array[j]
                swap = True
        if swap is False:
            return array

    return array


print(bubble_sort([1, 0, 9, 3, 1, 34, 4, 2, -1, 90, 66 ]))
