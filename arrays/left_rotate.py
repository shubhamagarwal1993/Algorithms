"""
Rotate an array(arr) of size(n) by (d) elements.

E.g.
For list [1, 2, 3, 4, 5, 6, 7, 8, 9] and x = 3
print [4, 5, 6, 7, 8, 9, 1, 2, 3]

How to solve:
 - Divide the array into different sets, where number of sets = GCD of n and d
   and move the elements within sets.
 - If GCD is 1 (n = 7 and d = 2), then elements will be moved within one set only,
   we start with temp = arr[0] and keep moving arr[I+d] to arr[I]. Finally store temp at right place.

E.g.
list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
n = 12
d = 3

GCD of 12 and 3 is 3
Now swap 1, 4, 7, 10 to be 4, 7, 10, 1 to get [4, 2, 3, 7, 5, 6, 10, 8, 9, 1, 11, 12]
Now swap 2, 5, 8, 11 to be 5, 8, 11, 2 to get [4, 5, 3, 7, 8, 6, 10, 11, 9, 1, 2, 12]
Now swap 3, 6, 9, 12 to be 6, 9, 12, 3 to get [4, 5, 6, 7, 8, 9, 10, 11, 12, 1, 2, 3]
"""

# -*- encoding: utf-8 *-*


def get_GCD(a, b):
    if b == 0:
        return a

    return get_GCD(b, a % b)


def left_rotate(input, input_size, d):
    gcd = get_GCD(d, input_size)
    for i in range(gcd):
        # store first element
        temp = input[i]
        curr_pos = i

        while(True):
            new_pos = curr_pos + d
            if new_pos >= input_size:
                new_pos = new_pos - input_size

            # We have gone around the array and came back
            if new_pos == i:
                break

            # Update curr position with new value
            input[curr_pos] = input[new_pos]

            curr_pos = new_pos
        # After rotating array, the initial element needs to be placed
        input[curr_pos] = temp


def main():
    input = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12]
    input_size = len(input)
    d = 3
    left_rotate(input, input_size, d)
    print(input)


if __name__ == '__main__':
    main()

