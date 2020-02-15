"""
Given a function foo() that returns integers from 1 to 5 with equal probability,
write a function that returns integers from 1 to 7 with equal probability using foo() only.
Minimize the number of calls to foo() method.
No floating point arithmetic allowed.
"""

# -*- encoding: utf-8 *-*

import math
import random


def rand5():
    return random.randint(1, 5)


def rand7():
    i = 5*rand5() + rand5() - 5
    if i < 22:
        return i % 7 + 1
    return rand7()


def rand10():
    i = 7*rand7() + rand7() - 7
    if i < 41:
        return i % 10 + 1
    return rand10()


def main():
    print(rand7())
    print(rand10())
    return


if __name__ == '__main__':
    main()

