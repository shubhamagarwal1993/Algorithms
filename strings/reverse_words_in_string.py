"""
Reverse words in string

E.g.
For "abc def ghi jkl", the output should be "jkl ghi def abc"
"""

# -*- encoding: utf-8 *-*


def reverse_string(input, left_index, right_index):
    if not input:
        return

    for i in range(0, int((right_index + 1 - left_index)/2)):
        temp = input[left_index + i]
        input = input[:left_index + i] + input[right_index - i] + input[left_index + i + 1:]
        input = input[:right_index - i] + temp + input[right_index - i + 1:]
    return input


def reverse_words_in_string(input):
    """
    Reverse all the words in the string
    """
    left_index = 0
    right_index = 0
    for i in range(len(input)):
        if input[i] == " ":
            right_index = i - 1
            input = reverse_string(input, left_index, right_index)
            left_index = i + 1
        elif i == len(input) - 1:
            right_index = i
            input = reverse_string(input, left_index, right_index)
    return input


def main():
    input = "abc def ghi jkl"
    print("Original string: ", input)
    input = reverse_string(input, 0, len(input) - 1)
    print("Reversed words: ", input)
    input = reverse_words_in_string(input)
    print("Reversed words: ", input)
    return

if __name__ == '__main__':
    main()

