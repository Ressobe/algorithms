def quick_sort(array, left, right):
    if left >= right:
        return
    partition_pos = partition(array, left, right)
    quick_sort(array, left, partition_pos - 1)
    quick_sort(array, partition_pos + 1, right)
    
    return array


def partition(array, left, right):
    i = left
    j = right - 1
    pivot = array[right]
    
    while i < j:
        while i < right and array[i] < pivot:
            i += 1
        while j > left and array[j] >= pivot:
            j -= 1
        if i < j:
            array[i], array[j] = array[j], array[i]
            
    if array[i] > pivot:
        array[i], array[right] = array[right], array[i]
    
    return i


array = [1, 0, 9, 3, 1, 34, 4, 2, -1, 90, 66]
print(quick_sort(array, 0, len(array) - 1))