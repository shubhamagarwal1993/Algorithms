"""
Print all sequences of numbers that sum up to a given number

Example
    For 3, output will be (1, 2), (2, 1), (1, 1, 1))
"""

# -*- encoding: utf-8 *-*


def summation_sequence(num, left, right):
    if left == right:
        print(num)
    else:
        for i in range(left, right + 1):
            num[left], num[i] = num[i], num[left]
            summation_sequence(num, left+1, right)
            num[left], num[i] = num[i], num[left]
    return


def main():
    # num = ["abcdefghij"]
    # index_1 = 2
    # index_2 = 5
    # print(num[0])
    # temp = num[0][index_1]
    # num[0] = num[0][:index_1] + num[0][index_2] + num[0][index_1 + 1:index_2] + temp + num[0][index_2+1:]
    # print(num[0])
    num = list("abc")
    summation_sequence(num, 0, 2)
    return


if __name__ == '__main__':
    main()

