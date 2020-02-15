"""
"utf8" indicates Unicode Transformation Format UTF-8,
which is an encoding that can handle every possible Unicode character.

UTF-8 can also be indicated by specifying "UTF8", "utf-8", or "UTF-8" for <encoding>.

Introduction to two Python objects used to represent raw byte data:
 - The bytes type
 - The bytearray type

A basic overview of bytes Objects:
 - Defining a Literal bytes Object
 - Defining a bytes Object With the Built-in bytes() Function
 - Operations on bytes Objects
 - bytearray Objects

bytes Objects
The bytes object is one of the core built-in types for manipulating binary data.
A bytes object is an immutable sequence of single byte values.
Each element in a bytes object is a small integer in the range 0 to 255.

Although a bytes object definition and representation is based on ASCII text,
it actually behaves like an immutable sequence of small integers in the range 0 to 255, inclusive.
That is why a single element from a bytes object is displayed as an integer.
"""


# -*- encoding: utf-8 *-*


import json


def basic_byte_manipulation(input):
    # A bytes literal is defined in the same way as a string literal with the addition of a 'b' prefix
    byte1 = b'foo bar baz'
    print(byte1)
    print(type(byte1))

    print(b'Contains embedded "double" quotes')
    print(b"Contains embedded 'single' quotes")
    print(b'''Contains embedded "double" and 'single' quotes''')
    print(b"""Contains embedded "double" and 'single' quotes""")

    # Only ASCII characters are allowed in a bytes literal.
    # Any character value greater than 127 must be specified using an appropriate escape sequence.
    byte1 = b'foo\xddbar'
    print(byte1)
    print(byte1[3])
    print(int(0xdd))

    # The 'r' prefix may be used on a bytes literal to disable processing of escape sequences, as with strings.
    byte1 = rb'foo\xddbar'
    print(byte1)
    print(byte1[3])
    print(chr(92))

    """
    Defining a bytes Object With the Built-in bytes() Function

    bytes(<s>, <encoding>) creates a bytes object from a string.
    bytes(<s>, <encoding>) converts string <s> to a bytes object, using str.encode()
    according to the specified <encoding>.
    """
    byte1 = bytes('foo.bar', 'utf8')
    print(byte1)
    print(type(byte1))

    """
    bytes(<size>) creates a bytes object consisting of null (0x00) bytes.
    bytes(<size>) defines a bytes object of the specified <size>, which must be a positive
    integer. The resulting bytes object is initialized to null (0x00) bytes
    """
    byte1 = bytes(8)
    print(byte1)
    print(type(byte1))

    """
    bytes(<iterable>) creates a bytes object from an iterable.
    bytes(<iterable>) defines a bytes object from the sequence of integers generated by <iterable>.
    <iterable> must be an iterable that generates a sequence of integers n in the range 0 ≤ n ≤ 255.
    """
    byte1 = bytes([100, 102, 104, 106, 108])
    print(byte1)
    print(type(byte1))
    print(byte1[2])

    """
    Operations on bytes Objects:

    Like strings, bytes objects support the common sequence operations.
     - in and not in operators.
     - The concatenation (+) and replication (*) operators.
     - Indexing and slicing.
     - Built-in functions like len(), min(), and max().
    """
    # in and not in operators.
    byte1 = b'abcde'
    if b'cd' in byte1:
        print(f''' b'cd' in {byte1}''')
    if b'foo' not in byte1:
        print(f''' b'foo' not in {byte1}''')

    # concatenation (+) and replication (*) operators.
    byte1 = b'abcde'
    print(byte1 + b'fghi')
    print(byte1 * 3)

    # Indexing and slicing.
    byte1 = b'abcde'
    print(byte1[2])
    print(byte1[1:3])

    # len of byte array
    byte1 = b'abcde'
    print(len(byte1))
    print(min(byte1))
    print(max(byte1))

    # count(), endswith(), and find()
    byte1 = b'foo,bar,foo,baz,foo,qux'
    print(byte1.count(b'foo'))
    print(byte1.endswith(b'qux'))
    print(byte1.find(b'baz'))
    print(byte1.split(sep=b','))
    print(byte1.center(30, b'-'))

    # byte object to list of integrers
    byte1 = b'foo,bar,foo,baz,foo,qux'
    print(list(byte1))

    """
    Hexadecimal / byte conversion

    Hexadecimal numbers are often used to specify binary data because two hexadecimal digits
    correspond directly to a single byte.
    The bytes class supports two additional methods that facilitate conversion to and from
    a string of hexadecimal digits.

    bytes.fromhex(<s>) returns the bytes object that results from converting each pair of hexadecimal
    digits in string <s> to the corresponding byte value.
    The hexadecimal digit pairs in <s> may optionally be separated by whitespace,
    which is ignored.

    This method is a class method, not an object method.
    It is bound to the bytes class, not a bytes object.
    """
    byte1 = bytes.fromhex(' aa 68 4682cc ')
    print(byte1)
    print(list(byte1))

    """
    b.hex() returns the result of converting bytes object b into a string of hexadecimal
    digit pairs. That is, it does the reverse of .fromhex().

    As opposed to .fromhex(), .hex() is an object method, not a class method.
    Thus, it is invoked on an object of the bytes class, not on the class itself.
    """
    byte1 = bytes.fromhex(' aa 68 4682cc ')
    print(byte1)
    print(byte1.hex())
    print(type(byte1.hex()))

    """
    bytearray Objects
    another binary sequence type called the bytearray.
    
    bytearray objects are very like bytes objects, despite some differences:
     - There is no dedicated syntax built into Python for defining a bytearray literal,
       like the 'b' prefix that may be used to define a bytes object.
       A bytearray object is always created using the bytearray() built-in function.
     - bytearray objects are mutable.
       You can modify the contents of a bytearray object using indexing and slicing.
    """
    # construction of bytearray
    byte_array1 = bytearray('foo.bar.baz', 'UTF-8')
    print(byte_array1)
    print(bytearray(6))
    print(bytearray([100, 102, 104, 106, 108]))

    # indexing and slicing of bytearray
    byte_array1 = bytearray('foo.bar.baz', 'UTF-8')
    print(byte_array1)

    byte_array1[5] = 0xee
    print(byte_array1)

    byte_array1[8:11] = b'qux'
    print(byte_array1)

    # A bytearray object may be constructed directly from a bytes object as well.
    byte_array1 = bytearray(b'foo')
    print(byte_array1)

    return


def main():
    input = "aabcd"
    basic_byte_manipulation(input)
    return


if __name__ == '__main__':
    main()
