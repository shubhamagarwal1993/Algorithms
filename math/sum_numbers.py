"""
Find sum of all numbers from 1 to 1,000,000
"""

# -*- encoding: utf-8 *-*

# import math


def sum(A, B):
    orig_A = A
    orig_B = B

    pos_A = True if A > 0 else False
    pos_B = True if B > 0 else False
    if not pos_A:
        A = -A
    if not pos_B:
        B = -B

    if A > B:
        temp = A
        A = B
        B = A

    sum = 0

    # At this point, A and B are positive and B >= A
    if A > 1:
        sum = (B*(B + 1) / 2) - (A * (A + 1) / 2)
    else:
        sum = (B*(B + 1) / 2)

    if abs(B) > abs(A):
        sum += A

    # Now add the sign back
    if not pos_A:
        A = -A
    if not pos_B:
        B = -B

    if B < A:
        return -sum
    return sum


def main():
    print(sum(A=0, B=0))
    print(sum(A=1, B=5))
    print(sum(A=0, B=5))
    print(sum(A=0, B=-5))
    print(sum(A=-1, B=-5))
    print(sum(A=-4, B=-4))
    print(sum(A=-3, B=5))

if __name__ == '__main__':
    main()

