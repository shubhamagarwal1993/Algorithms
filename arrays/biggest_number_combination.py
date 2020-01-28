"""
Arrange given numbers to form the biggest number
E.g.
For [54, 546, 548, 60], 6054854654 gives the largest value
For [1, 34, 3, 98, 9, 76, 45, 4], 998764543431 gives the largest value
"""

# -*- encoding: utf-8 *-*

import math
import sys
import functools


ASCII_LEN = 256


def getDigits(num):
    if num > 0:
        return int(math.log10(num))+1
    elif num == 0:
        return 1
    else:
        return int(math.log10(-num)) + 2  # +1 if you don't count the '-'


def comparator(a, b):
    """
        Compare ab and ba and return the bigger one
    """
    a_digits_len = getDigits(a)
    b_digits_len = getDigits(b)
    a_new = b + (a * (10**b_digits_len))
    b_new = (b * (10**a_digits_len)) + a
    return ((b_new > a_new) - (b_new < a_new))


def compare(mycmp):
    # Convert a cmp= function into a key= function
    class K(object):
        def __init__(self, obj, *args):
            self.obj = obj

        def __lt__(self, other):
            return mycmp(self.obj, other.obj) < 0

        def __gt__(self, other):
            return mycmp(self.obj, other.obj) > 0

        def __eq__(self, other):
            return mycmp(self.obj, other.obj) == 0

        def __le__(self, other):
            return mycmp(self.obj, other.obj) <= 0

        def __ge__(self, other):
            return mycmp(self.obj, other.obj) >= 0

        def __ne__(self, other):
            return mycmp(self.obj, other.obj) != 0

    return K


def concatIntegers(a, b):
    """
        return ab
    """
    b_digits_len = getDigits(b)
    return b + (a * (10**b_digits_len))


def getBiggestNumberFromList(input):
    if len(input) < 1:
        return 0

    # sort the array
    sorted_array = sorted(input, key=compare(comparator))
    print(input)
    print(sorted_array)

    # store the biggest number in this
    biggest_number = sorted_array[0]

    # concat the rest of the integers
    for i in range(1, len(sorted_array)):
        biggest_number = concatIntegers(biggest_number, sorted_array[i])
    return biggest_number


def main():
    input = [54, 546, 548, 60]
    biggest_number = getBiggestNumberFromList(input)
    print("Biggest number - ", biggest_number)

if __name__ == '__main__':
    main()

