def insertion_sort(array: list) -> list:
    length_array = len(array)
    for i in range(1, length_array):
        current = array[i]
        j = i - 1
        while j >= 0 and current < array[j]:
            array[j + 1] = array[j]
            j -= 1
            
        array[j + 1] = current
            
    return array


print(insertion_sort(([0, 2, 1, 8, 3, 4, 22, 90, 4, 1, -20, 45, 82])))