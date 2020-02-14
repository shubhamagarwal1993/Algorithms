"""
This will give a basic overview of string manipulation
 - String Operators
 - Built-in String Functions
 - String Indexing
 - String Slicing
 - Specifying a Stride in a String Slice
 - Interpolating Variables Into a String
 - Modifying Strings
 - Built-in String Methods
"""

# -*- encoding: utf-8 *-*


import json


def basic_string_manipulation():
    # + concatenate strings
    str1 = "foo"
    str2 = "bar"
    str3 = str1 + str2
    print(str3)

    # * multiply operator
    str1 = "foo"
    count = 3  # If count <= 0, * will return an empty string
    str2 = count * str1
    print(str2)

    # in and not in operators
    str1 = "abcdefgh"
    str2 = "cde"
    str3 = "fghi"
    if str2 in str1:
        print("found", str2, "in", str1)
    if str3 not in str1:
        print(str3, "not found in", str1)

    """
    ASCII / Unicode conversion
    """
    # chr()	Converts an integer to a character
    print("The string representation of ASCII 97 is", chr(97), "and 35 is", chr(35))
    print("The string representation of Unicode 8364 is", chr(8364), "and 8721 is", chr(8721))

    # ord() Converts a character to an integer - supports ASCII and Unicode
    print("The ASCII value of a is", ord('a'), "and # is", ord('#'))
    print("The Unicode value of € is", ord('€'), "and ∑ is", ord('∑'))

    """
    String represntation of object
    Virtually any object in Python can be rendered as a string.
    """
    # str() returns the string representation of object
    print("string representation of object - ", str(3+4j))
    print(json.dumps(['foo', {'bar': ('baz', None, 1.0, 2)}]))
    print(json.dumps({'4': 5, '6': 7}, sort_keys=True, indent=4))

    """
    String Slicing
    A form of indexing syntax that extracts substrings from a string, known as string slicing.
    s[m:n] returns the portion of string s starting with position m, and up to but not including position n
    """
    str1 = 'foobar'
    print("string from pos 2 to 5 is", str1[2:5])
    print("string from pos 0 to 3 is", str1[:3])
    print("string from pos 3 to end is", str1[3:len(str1)])
    print("string from pos 0 to end is", str1[:])

    """
    Stride in a String Slice

    Stride: indicates how many characters to jump after retrieving each character in the slice.
    The 3rd index in a string slice indicates a stride (also called a step)

    E.g. For string 'foobar', the slice 1:5:2
        starts with the 2nd character
        ends with the 5th character
        every second character is skipped

    A negative stride steps backward through the string.
    """
    str1 = 'foobar'
    print(str1[0:6:2])
    print(str1[1:6:2])
    print(str1[5:0:-2])
    print(str1[::-1])

    """
    Formatted String Literal (a string formatting mechanism to interpolate variables into a string)
    Also called f-string

    Specify either a lowercase f or uppercase F directly before the opening quote of the string literal.
    This tells Python it is an f-string instead of a standard string.

    Specify any variables to be interpolated in curly braces ({})
    """
    int1 = 20
    int2 = 25
    prod1 = int1 * int2
    print(f'The product of {int1} and {int2} is {prod1}')

    str1 = 'Bark'
    print(f'A dog says {str1}!')
    print(f"A dog says {str1}!")
    print(f'''A dog says {str1}!''')

    """
    Substring replacement in a string

    Since strings are immutable, we can only edit by creating a new copy of the origianl string
    """
    str1 = "foobar"
    str2 = str1[:3] + 'x' + str1[4:]
    print(f"replace 3rd index with x in {str1} to get {str2}")

    str1 = 'foobar'
    str1 = str1.replace('o', 'x')
    print(str1)

    """
    Some useful inbuilt functions
     - capitalize() returns a copy of string with 1st char converted to uppercase and all other chars converted to
       lowercase.
     - lower() or upper() returns a copy of string with all alphabetic characters converted to lowercase or uppercase.
     - swapcase() returns a copy of string with uppercase alphabetic characters converted to lowercase and vice versa.
     - title() returns a copy of string in which the first letter of each word is converted to uppercase and remaining
       letters are lowercase. E.g. 'the sun also rises'.title() becomes 'The Sun Also Rises'.
    """
    str1 = 'foO BaR BAZ quX'
    print(str1.capitalize())

    return


def main():
    basic_string_manipulation()
    return


if __name__ == '__main__':
    main()

