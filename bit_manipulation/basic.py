# -*- encoding: utf-8 *-*

"""
Basic knowledge of locial and bitwise operations in python3

Topics covered:
 - Bitwise AND (&)
 - Bitwise OR (|)
 - Bitwise XOR (^)
 - Bitwise 1’s complement (-)
 - Left-shift (<<)
 - Right-shift(>>)
"""

def main():
    # Binary representation
    print(bin(5))
    print(bin(7))

    """
    logical (and) operation
        Sees the value on the left. If it has a True Boolean value,
        it returns whatever value is on the right

    bitwise (&) operation
        Acts on each bit at once
    """
    print(5 and 7)
    print(5 & 7)
    print(0b101 and 0b111)
    print(0b101 & 0b111)

    """
    logical (or) operation
        Sees the value on the left. If it has a True Boolean value,
        it returns whatever value is on the right

    bitwise (|) operation
        Acts on each bit at once
    """
    print(6 or 1)
    print(6 | 1)
    print(0b110 or 0b001)
    print(0b110 | 0b001)

    """
    logical (xor) operation -> there is nothing like this really
    != satisfies this

    bitwise (^) operation
        Acts on each bit at once
        xor (^) of same numbers will be 0
    """
    print(6 ^ 1)
    print(6 ^ 6)

    """
    bitsie 1s compliment (returns its one’s complement)
        For this, it flips the bits until it reaches the first 0 from right.
        ~x is the same as -x-1
    """
    print(~1)

    return


if __name__ == '__main__':
    main()

