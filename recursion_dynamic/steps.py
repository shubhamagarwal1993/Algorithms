"""
Given a recursive function, memoize it
"""

# -*- encoding: utf-8 *-*

def three_steps(input, memo):
    if input < 0:
        return -1
    if input >= 0 and input <= 2:
        return 1
    if memo[input - 1] > 0:
        return memo[input - 1]
    memo[input - 1] = three_steps(input - 1, memo) + three_steps(input - 2, memo) + three_steps(input - 3, memo)
    return memo[input - 1]

def main():
    input = 5
    memo = [0] * 5
    print(three_steps(input, memo))

    return

if __name__ == '__main__':
    main()
