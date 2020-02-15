"""
Find out home many square numbers are there in the range [A, B] where A <= B and are both integers.
Both A and B might be negative
"""

# -*- coding: utf-8 -*-

import math


def findSquares(A, B):
    if B <= 0:
        return

    if A <= 0:
        A = 1

    for curr in range(A, B+1, 1):
        if not math.sqrt(curr) - int(math.sqrt(curr)):
            print(curr)


def main():
    A = -2
    B = 8
    findSquares(A=A, B=B)

if __name__ == '__main__':
    main()

