def find_min_index(values):
    min_index = 0

    for i in range(1, len(values)):
        if values[i] < values[min_index]:
            min_index = i

    return min_index


def selection_sort(values):
    sorted_list = []

    while len(values) > 0:
        min_value_index = find_min_index(values)

        sorted_list.append(values.pop(min_value_index))

    return sorted_list
