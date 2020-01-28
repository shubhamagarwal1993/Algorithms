"""
Given list [1, [2, 3], [[[4]]], [[[[[[[[5, 6, 7, [[8, 9, [], [], [], [[[]]]]]]]]]]]]]]
return [1, 2, 3, 4, 5, 6, 7, 8, 9]
"""

# -*- encoding: utf-8 *-*


def get_flattened_list_recursive(input):
    flattened_list = []

    for i in range(len(input)):
        if type(input[i]) == list:
            flattened_list = flattened_list + get_flattened_list_recursive(input[i])
        else:
            flattened_list.append(input[i])
    return flattened_list


def main():
    input = [1, [2, 3], [[[4]]], [[[[[[[[5, 6, 7, [[8, 9, [], [], [], [[[]]]]]]]]]]]]]]
    flattened_list = get_flattened_list_recursive(input)
    print(input)
    print(flattened_list)


if __name__ == '__main__':
    main()

