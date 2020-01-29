"""
Find if given string is a substring of another string and return position

E.g.
    For "dbabcdcaadcbaa", and "abcd", the output should be 2
    For "abcdef", and "bcd", the output should be -1 since substring does not exist
"""

# -*- encoding: utf-8 *-*


def find_substring_naive(input, pattern):
    """
    Time complexity: O(mn) where m and n are string lengths of input and pattern
    """
    if input is None or pattern is None:
        return -1
    if len(pattern) > len(input):
        return -1

    input_index = 0
    pattern_index = 0
    while input_index < len(input):
        if input[input_index] == pattern[pattern_index]:
            if pattern_index == len(pattern) - 1:
                return input_index - len(pattern) + 1
            pattern_index += 1
            input_index += 1
        else:
            input_index -= pattern_index - 1
            pattern_index = 0
    return -1


def compute_LPS_array(pattern, lps):
    """
    Fills lps[] for given patttern pat[0..M-1]
    """
    # length of the previous longest prefix suffix
    max_len = 0

    # calculate lps[i] for i = 1 to len(pattern) - 1
    index = 1
    while index < len(pattern):
        if pattern[index] == pattern[max_len]:
            max_len += 1
            lps[index] = max_len
            index += 1
        else:
            # case for pattern[index] != pattern[max_len]
            if max_len != 0:
                max_len = lps[max_len - 1]
                # do not increment index here
            else:
                # case for max_len == 0
                lps[index] = 0
                index += 1


def find_substring_kpm(input, pattern):
    """
    kpm - Knuth Morris Pratt
    Time Complexity: O(n) where n

    KMP matching algorithm: whenever we detect a mismatch (after some matches),
    we already know some of the characters in the text of the next window.
    Take advantage of this information to avoid matching the characters that we know
    will anyway match.

    E.g.
    Matching Overview
    txt = "AAAAABAAABA"
    pat = "AAAA"

    compare first window of txt with pat
    txt = "AAAAABAAABA"
           ----
    pat = "AAAA"  [Initial position]

    We find a match. This is same as Naive String Matching.

    In the next step, we compare next window of txt with pat.
    txt = "AAAAABAAABA"
               -
    pat =  "AAAA" [Pattern shifted one position]
               -

    This is where KMP does optimization over Naive. In this second window,
    we only compare fourth A of pattern with fourth character of current window
    of text to decide whether current window matches or not.

    Since we know first three characters will anyway match, we skipped
    matching first three characters.

    Peprocessing:
    In order to know how many characters to be skipped, we pre-process pattern and
    prepare an integer array lps[] that tells us the count of characters to be skipped.
    lps - longest proper suffix or longest proper prefix

    Preprocessing Overview:
    KMP algorithm preprocesses pat[] and constructs an auxiliary lps[] of size m
    (same as size of pattern) which is used to skip characters while matching.

    A proper prefix is prefix with whole string not allowed.
    E.g.
    For "ABC",
    Prefixes are "A", "AB", and "ABC"
    Proper prefixes are "", "A", and "AB"
    Suffixes of the string are "", "C", "BC", and "ABC"

    Examples of lps[] construction:
    For the pattern “AAAA”
    lps[] is [0, 1, 2, 3]

    For the pattern “ABCDE”
    lps[] is [0, 0, 0, 0, 0]

    For the pattern “AABAACAABAA”
    lps[] is [0, 1, 0, 1, 2, 0, 1, 2, 3, 4, 5]

    For the pattern “AAACAAAAAC”
    lps[] is [0, 1, 2, 0, 1, 2, 3, 3, 3, 4]

    For the pattern “AAABAAA”
    lps[] is [0, 1, 2, 0, 1, 2, 3]
    """
    # create lps[] that will hold the longest prefix suffix values for pattern
    lps = [0] * len(pattern)

    # Preprocess the pattern (calculate lps[] array)
    compute_LPS_array(pattern, lps)

    input_index = 0
    pattern_index = 0
    while input_index < len(input):
        if pattern[pattern_index] == input[input_index]:
            input_index += 1
            pattern_index += 1
        if pattern_index == len(pattern):
            print("Found pattern at index", input_index - pattern_index)
            pattern_index = lps[pattern_index - 1]
        elif input_index < len(input) and pattern[pattern_index] != input[input_index]:
            # Do not match lps[0..lps[j-1]] characters, they will match anyway
            if pattern_index != 0:
                pattern_index = lps[pattern_index - 1]
            else:
                input_index = input_index + 1


def main():
    input = "aabcd"
    pattern = "abcd"
    print(find_substring_naive(input, pattern))

    txt = "ABABDABACDABABCABAB"
    pat = "AB"
    find_substring_kpm(txt, pat)

    return


if __name__ == '__main__':
    main()

