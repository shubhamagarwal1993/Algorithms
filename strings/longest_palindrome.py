"""
Reverse words in string

E.g.
For "abc def ghi jkl", the output should be "jkl ghi def abc"
"""

# -*- encoding: utf-8 *-*


def longest_palindrome(input):
    """
    Time complexity: O(n^2), Space complexity: O(1)
    Step to generate odd length palindrome:
        Fix a centre and expand in both directions for longer palindromes
    Step to generate even length palindrome:
        Fix two centre ( low and high ) and expand in both directions for longer palindromes
    """
    longest_palindrome_length = 1
    start_index = 0
    low = 0
    high = 0

    # One by one consider every character as center point of even and odd length palindromes
    for i in range(1, len(input)):
        # even length palindrome with center points i-1 and i
        low = i - 1
        high = i
        while low >= 0 and high < len(input) and input[low] == input[high]:
            if high - low + 1 > longest_palindrome_length:
                longest_palindrome_length = high - low + 1
                start_index = low
            low -= 1
            high += 1

        # odd length palindrome with centre point i
        low = i - 1
        high = i + 1
        while low >= 0 and high < len(input) and input[low] == input[high]:
            if high - low + 1 > longest_palindrome_length:
                longest_palindrome_length = high - low + 1
                start_index = low
            low -= 1
            high += 1

    print("Longest substring palindrome is ")
    for i in range(start_index, start_index + longest_palindrome_length):
        print(input[i], end=" ")
    print("with length ", longest_palindrome_length)


def is_palindrome(input):
    if input is None:
        return False

    left = 0
    right = len(input) - 1
    input_len = len(input)

    for i in range(int((right - left) / 2)):
        if input[i] != input[input_len - 1 - i]:
            return False
    return True


def main():
    input = "forgeeksskeegfor"
    longest_palindrome(input)

    input = "abccuba"
    print(input, "is palindrome - ", is_palindrome(input))
    return

if __name__ == '__main__':
    main()

