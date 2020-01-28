"""
Given array, find 2 numbers that sum up to k
Given array, find 3 numbers that sum up to k
Given array, find 4 numbers that sum up to k

E.g.
For [2, 7, 4, 3, 5, 1, 3] and k=9
2 array => 2 and 7
3 array => 2, 4, and 3
4 array => 2, 3, 1, and 3
"""

# -*- encoding: utf-8 *-*


def print2ArraySum(input, k):
    """
    Time complexity: O(n) where n is length of input
    Space complexity: O(n) where n is length of input
    """
    check_dict = {}

    for i in range(0, len(input)):
        curr_element = input[i]
        required_element = k - curr_element
        if required_element in check_dict:
            print("The 2 values are ", curr_element, " and ", required_element)
        check_dict[curr_element] = 1

    return


def print3ArraySum(input, k):
    """
    Time complexity: O(n^2) where n is length of input
    Space complexity: O(n) where n is length of input
    """
    # Use sorted to not modify an argument inplace
    input = sorted(input)

    # loop over sorted array
    for i in range(0, len(input) - 2):
        left_pos = i + 1
        right_pos = len(input) - 1
        curr_val = input[i]
        while(left_pos < right_pos):
            left_val = input[left_pos]
            right_val = input[right_pos]
            if curr_val + left_val + right_val == k:
                print("The 3 values are ", curr_val, ", ", left_val, ", and ", right_val)
            if curr_val + left_val + right_val < k:
                left_pos += 1
            else:
                right_pos -= 1
    return


class x_y:
    """
    Hold (x, y) pairs and their sum

    Time complexity: O(n^2log(n)) where n is length of input
    Space complexity: O(n) where n is length of input
    """
    def __init__(self, sum, x, y):
        self.sum = sum
        self.x = x
        self.y = y

    def __eq__(self, other):
        return ((self.sum, self.x, self.y) == (self.sum, self.x, self.y))

    def __ne__(self, other):
        return ((self.sum, self.x, self.y) != (other.sum, other.x, other.y))

    def __lt__(self, other):
        return ((self.sum) < (other.sum))

    def __le__(self, other):
        return ((self.sum) <= (other.sum))

    def __gt__(self, other):
        return ((self.sum) > (other.sum))

    def __ge__(self, other):
        return ((self.sum) >= (other.sum))

    def __repr__(self):
        return "%s %s %s" % (self.sum, self.x, self.y)


def not_repeat(a, b):
    if a.x == b.x or a.x == b.y or a.y == b.x or a.y == b.y:
        return False
    return True


def print4ArraySum(input, k):
    """
    Find all the pairs and store them in a dict
    """
    list_pairs = []

    for i in range(len(input) - 1):
        for j in range(i+1, len(input)):
            temp = x_y(input[i]+input[j], input[i], input[j])
            list_pairs.append(temp)

    # Sort by sum of x and y
    list_pairs = sorted(list_pairs)

    left_pos = 0
    right_pos = len(list_pairs) - 1

    while right_pos >= 0 and left_pos < len(list_pairs):
        if list_pairs[left_pos].sum + list_pairs[right_pos].sum == k and not_repeat(list_pairs[left_pos], list_pairs[right_pos]):
            print(k, " ", list_pairs[left_pos].sum, " ", list_pairs[right_pos].sum, " = ", list_pairs[left_pos].x, ", ", list_pairs[left_pos].y, ", ", list_pairs[right_pos].x, ", ", list_pairs[right_pos].y)
            left_pos += 1
        elif list_pairs[left_pos].sum + list_pairs[right_pos].sum < k:
            left_pos += 1
        else:
            right_pos -= 1

    return


def main():
    input = [2, 1, 7, 4, 3, 4, 1, 3]
    k = 8
    print2ArraySum(input, k)
    print3ArraySum(input, k)
    print4ArraySum(input, k)


if __name__ == '__main__':
    main()

