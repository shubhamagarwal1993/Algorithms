"""
Edit distance is the minimum change needed for str1 to become str2

E.g.
For str1 = "temp", and str2 = "aaaa", the edit distance is 4
For str1 = "temper" and str2 = "tamp", the edit distance is 3
"""

# -*- encoding: utf-8 *-*


def edit_distance_recursion(str1, str1_len, str2, str2_len):
    """
    Time complexity: O(3^m) where m is lenght of smaller string
    """

    if str1_len == 0:
        return str2_len

    if str2_len == 0:
        return str1_len

    if str1[str1_len - 1] == str2[str2_len - 1]:
        return edit_distance_recursion(str1, str1_len - 1, str2, str2_len - 1)

    return 1 + min(
        edit_distance_recursion(str1, str1_len - 1, str2, str2_len),
        edit_distance_recursion(str1, str1_len, str2, str2_len - 1),
        edit_distance_recursion(str1, str1_len - 1, str2, str2_len - 1)
    )


def edit_distance(str1, str2):
    """
    Time complexity: O(mn) where m is length of str1 and n is length of str2
    Space complecity: O(mn) where m is length of str1 and n is length of str2
    """
    str1_len = len(str1)
    str2_len = len(str2)

    # Make a 2D array and initalize it to 0
    dp = [[0 for i in range(len(str2) + 1)] for j in range(len(str1) + 1)]

    for i in range(str1_len + 1):
        for j in range(str2_len + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

    for i in range(len(str1) + 1):
        for j in range(len(str2) + 1):
            print(dp[i][j], end=" ")
        print()

    return dp[str1_len][str2_len]


def edit_distance_1(str1, str2):
    """
    Time complexity: O(mn) where m is length of str1 and n is length of str2
    Space complecity: O(mn) where m is length of str1 and n is length of str2
    """
    str1_len = len(str1)
    str2_len = len(str2)

    # Make a 2D array and initalize it to 0
    dp = [[0 for i in range(len(str2) + 1)] for j in range(len(str1) + 1)]

    for i in range(str1_len + 1):
        for j in range(str2_len + 1):
            if i == 0:
                dp[i][j] = j
            elif j == 0:
                dp[i][j] = i
            elif str1[i - 1] == str2[j - 1]:
                dp[i][j] = dp[i-1][j-1]
            else:
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])

    for i in range(len(str1) + 1):
        for j in range(len(str2) + 1):
            print(dp[i][j], end=" ")
        print()

    return dp[str1_len][str2_len]


def main():
    str1 = "temp"
    str2 = "teamp"
    # print("recursive edit distance - ", edit_distance_recursion(str1, len(str1), str2, len(str2)))
    # print("dp edit distance - ", edit_distance(str1, str2))
    print("edit distance is 1 - ", edit_distance_1(str1, str2))
    return


if __name__ == '__main__':
    main()

