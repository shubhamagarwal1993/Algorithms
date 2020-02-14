"""
Print all permutatinos of string

E.g.
For "BAA"
AAB
ABA
BAA
"""

# -*- encoding: utf-8 *-*


def swap(char1, char2):
    print(char1, " ", char2)
    temp = char1
    char1 = char2
    char2 = temp
    print(char1, " ", char2)
    # input = input[:left_index + i] + input[right_index - i] + input[left_index + i + 1:]
    return


def permute_recursion_with_duplicates(input, l_index, r_index):
    """
    """
    if l_index == r_index:
        print(input)
    else:
        for i in range(l_index, r_index):
            swap(input[l_index], input[i])
            permute_recursion_with_duplicates(input, l_index + 1, r_index)
            swap(input[l_index], input[i])


def permute_recursion_without_duplicates(input, l_index, r_index):
    """
    """
    return


def main():
    input = "AB"

    # print permutations in lexicographical order
    # sort(str.begin(), str.end());

    permute_recursion_with_duplicates(input, 0, len(input))
    permute_recursion_without_duplicates(input, 0, len(input))
    return


if __name__ == '__main__':
    main()

