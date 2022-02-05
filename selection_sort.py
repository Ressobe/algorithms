def selection_sort(array: list) -> list:
    for i in range(0, len(array)):
        min_index = i
        for j in range(i, len(array)):
            if array[j] < array[min_index]:
                min_index = j
                
        array[min_index], array[i] = array[i], array[min_index]
    
    return array
                
        
        
print(selection_sort([0, 2, 1, 8, 3, 4, 22, 90, 4, 1, -20, 45, 82]))