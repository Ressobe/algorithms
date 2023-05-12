def merge_sort(array: list) -> list:
    if len(array) <= 1:
        return []

    left_array = array[: len(array) // 2]
    right_array = array[len(array) // 2:]

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


def SCALAJ(A, p, q, r):
    n1 = q - p + 1  # Długość lewej podtablicy
    n2 = r - q  # Długość prawej podtablicy

    # L = A[p:p+n1]  # Skopiuj elementy lewej podtablicy do tablicy L
    # R = A[q+1:q+1+n2]  # Skopiuj elementy prawej podtablicy do tablicy R

    L = []
    R = []

    for i in range(n1):
        L.append(A[p+i])

    for j in range(n2):
        R.append(A[q+j+1])

    i = j = 0  # Indeksy bieżących elementów w tablicach L i R
    k = p  # Indeks bieżącego elementu w tablicy A

    while i < n1 and j < n2:
        if L[i] <= R[j]:  # Wybierz mniejszy element spośród L[i] i R[j]
            A[k] = L[i]  # Wstaw mniejszy element do tablicy A
            i += 1
        else:
            A[k] = R[j]  # Wstaw mniejszy element do tablicy A
            j += 1
        k += 1

    while i < n1:
        A[k] = L[i]  # Wstaw pozostałe elementy z tablicy L do tablicy A
        i += 1
        k += 1

    while j < n2:
        A[k] = R[j]  # Wstaw pozostałe elementy z tablicy R do tablicy A
        j += 1
        k += 1


def SORT_SCALANIE(A, p, r):
    if p < r:
        q = (p + r) // 2
        SORT_SCALANIE(A, p, q)
        SORT_SCALANIE(A, q + 1, r)
        SCALAJ(A, p, q, r)


def main():
    array = [0, 2, 1, 8, 3, 4, 22, 90, 4, 1, -20, 45, 82]
    print(merge_sort(array))


if __name__ == "__main__":
    main()
