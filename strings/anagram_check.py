"""
Check if 2 strings are anagrams

E.g.
For "abcd" and "bdca", it should be True
"""

# -*- encoding: utf-8 *-*


def are_anagram(str1, str2):

    if len(str1) != len(str2):
        return False

    compare_map = {}
    for i in range(len(str1)):
        str1_char = str1[i]
        if str1_char in compare_map:
            str1_char_count = compare_map[str1_char] + 1
            compare_map[str1_char] = str1_char_count
        else:
            compare_map[str1_char] = 1

    for i in range(len(str2)):
        str2_char = str2[i]
        if str2_char in compare_map:
            if compare_map[str2_char] > 1:
                str2_char_count = compare_map[str2_char] - 1
                compare_map[str2_char] = str2_char_count
            elif compare_map[str2_char] == 1:
                compare_map.pop(str2_char)
        else:

            return False

    if len(compare_map) == 0:
        return True
    return False


def main():
    str1 = "aabcd"
    str2 = "bdaca"
    if are_anagram(str1, str2):
        print("Anagram True")
    else:
        print("Not anagram")
    return


if __name__ == '__main__':
    main()

