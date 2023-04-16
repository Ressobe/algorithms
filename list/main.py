def get_size_of_nested_list(arr: list):
    count = 0
    for e in arr:
        if type(e) == list:
            count += get_size_of_nested_list(e)
        else:
            count += 1
    return count


arr = [1, 2, [3, 4, [5, 9, [0]]], 3]
print(get_size_of_nested_list(arr))
