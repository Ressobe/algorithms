def merge_sort(array: list) -> list:
    if len(array) <= 1:
        return 0

    left_array = array[: len(array) // 2]
    right_array = array[len(array) // 2 :]

    merge_sort(left_array)
    merge_sort(right_array)

    i, j, k = 0, 0, 0
    while i < len(left_array) and j < len(right_array):
        if left_array[i] < right_array[j]:
            array[k] = left_array[i]
            i += 1
        else:
            array[k] = right_array[j]
            j += 1
        k += 1

    while i < len(left_array):
        array[k] = left_array[i]
        i += 1
        k += 1

    while j < len(right_array):
        array[k] = right_array[j]
        j += 1
        k += 1

    return array


print(merge_sort([0, 2, 1, 8, 3, 4, 22, 90, 4, 1, -20, 45, 82]))
