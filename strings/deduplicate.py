"""
Remove adjacent duplicates from a string

Modification of a string while iterating it is dangerous
"""

# -*- encoding: utf-8 *-*

def deduplicate(input):
    if len(input) <= 1:
        return input

    # index of characters which are duplicate
    duplicate_pos = []

    for idx in range(1, len(input)):
        if input[idx] == input[idx-1]:
            duplicate_pos.append(idx)

    # Now delete chars from string in reverse order so that index is not affected for future deletes
    for idx in range(len(duplicate_pos) - 1, -1, -1):
        index = duplicate_pos[idx]
        input = input[:index] + input[index+1:]

    return input

def main():
    str_clean = deduplicate("aabbcc")
    print(str_clean)
    return

if __name__ == '__main__':
    main()
