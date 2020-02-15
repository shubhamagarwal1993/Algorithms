"""
Calculate cubic root of a number to 3 deciaml placess


Examples:
    For n = 3, cubic root is 1.442250
    For n = 8, cubic root is 2.000000
"""

# -*- encoding: utf-8 *-*

import math


def find_error(calculated_ans, num):
    return abs(calculated_ans**3 - num)


def cubic_root(num):
    """
    Use binary search.

    define error e. Let us say 0.0000001 in our case.

    Steps:
    - initialize start = 0 and end = n
    - calculate mid = (start + end)/2
    - Check if the absolute value of (n – mid*mid*mid) < e.
      - If this condition holds true then mid is our answer so return mid.
    - If (mid*mid*mid)>n then set end=mid
    - If (mid*mid*mid)<n set start=mid

    Time complexity: O(log N)
    """
    # start and end for binary search
    start = 0
    end = num

    # precision / error
    e = 0.0001

    while(True):
        calculated_ans = (start + end) / 2
        # Find the pricision or error of our answer
        err = find_error(calculated_ans, num)

        # If our precision is within expected range
        if err <= e:
            break

        if (calculated_ans**3 > num):
            end = calculated_ans
        else:
            start = calculated_ans

    return calculated_ans


def main():
    num = 27
    print(cubic_root(num))

if __name__ == '__main__':
    main()

