"""
Every number occurs twice except one number that occurs once
Find the number that occurs once

E.g.
Given list [5, 2, 3, 1, 5, 3, 2], return 1
"""

# -*- encoding: utf-8 *-*


def get_non_repeating_number(input):
    """
    The XOR of same numbers is 0.

    Thus the XOR of all repeating numbers will be 0
    The XOR of 0 and single non-repeating number is the number itself.
    """
    if len(input) == 0:
        return

    val = 0
    for i in range(len(input)):
        val = val ^ input[i]

    return val


def main():
    input = [5, 2, 3, 1, 5, 3, 2]
    non_repeating_number = get_non_repeating_number(input)
    print("Non repeating number - ", non_repeating_number)


if __name__ == '__main__':
    main()

