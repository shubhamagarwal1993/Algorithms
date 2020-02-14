"""
Find the first non-repeating character in a string
E.g.
For "GeeksforGeeks", the output should be 'f'
For "GeeksQuiz", the output should be 'G'
"""

# -*- encoding: utf-8 *-*

import math
import sys


ASCII_LEN = 256


def getFirstNonRepeatingChar(input):
    """
    There are 256 ascii characters
    0 for does not exist
    1 for exists once
    2 for exists twice or more
    """
    # Initilize a list with all ascii chars as 0
    char_flag_list = []
    for i in range(0, ASCII_LEN):
        char_flag_list.append(0)

    # Find count of each character in given list
    for i in range(0, len(input)):
        ascii_val = ord(input[i])
        if char_flag_list[ascii_val] < 2:
            char_flag_list[ascii_val] += 1

    # Find the first character that has an count of 1
    for i in range(0, len(input)):
        ascii_val = ord(input[i])
        if char_flag_list[ascii_val] == 1:
            return chr(ascii_val)
    return ''


def main():
    input = "GeeksForGeeks"
    non_repeating_char = getFirstNonRepeatingChar(input)
    print("First non repeating char - ", non_repeating_char)

if __name__ == '__main__':
    main()

