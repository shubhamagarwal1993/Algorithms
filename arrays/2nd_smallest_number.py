"""
Find the 2nd smallest number from array

E.g.
Given list [1, 2, 3, 4, 5, 6], return 2
"""

# -*- encoding: utf-8 *-*


def get_second_smallest(input):
    """
    Maintain first value to be smaller than second element in list, E.g. [1, 2]
    Do not exceed 2 values in list

    Cases:

    [4]
    1.) if list len == 1
        a.) if curr_val >= smallest_list[0], append to end
        b.) if curr_val < smallest_list[0], prepend to start
        return
    Now list len == 2
    2.) If curr_val > smallest_list[1], pass
    3.) If curr_val >= smallest_list[0] and < smallest_list[1], pop last element, and append curr_val to end
    4.) If curr_val < smallest_list[0], prepend to start, pop last element
    """
    if input is None or len(input) < 2:
        return

    smallest_value_list = [input[0]]

    for i in range(1, len(input)):
        curr_val = input[i]

        if len(smallest_value_list) == 1:
            if curr_val >= smallest_value_list[0]:
                smallest_value_list.append(curr_val)
            else:
                smallest_value_list = [curr_val] + smallest_value_list
            continue
        # There are 2 elements in list at this point
        if curr_val > smallest_value_list[1]:
            pass
        elif curr_val >= smallest_value_list[0] and curr_val < smallest_value_list[1]:
            smallest_value_list.pop(-1)
            smallest_value_list.append(curr_val)
        else:
            smallest_value_list[1] = smallest_value_list[0]
            smallest_value_list[0] = curr_val
    return smallest_value_list[0]


def main():
    input = [84, 39, 2, 1, 49, 49, 2, 1]
    second_smallest_int = get_second_smallest(input)
    print(input)
    print("2nd smallest value in list", second_smallest_int)


if __name__ == '__main__':
    main()

