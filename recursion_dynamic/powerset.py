# -*- encoding: utf-8 *-*

"""
Every character has 2 choices - to be present or not
Total combinations - 2 * 2 * ...(number of characters in string) = 2^len(input)
"""

def power_set_iterate(input):
    # Size of power set will be 2^len(input)
    total_combinations = 2**len(input)

    # run a counter from 000 to 111
    for i in range(total_combinations):
        print("{", end=" ")
        for j in range(len(input)):
            if i & (1 << j):
                print(input[j], end=" ")
        print("}", end=" ")
        print()
    return


def main():
    input = "abc"

    # iterative method
    power_set_iterate(input)
    return


if __name__ == '__main__':
    main()

