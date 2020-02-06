"""
Fibonacci series
"""

# -*- encoding: utf-8 *-*

def fib(count):
    if count < 0:
        return

    if count >= 0 and count < 2:
        print(count)
        return

    n1 = 0
    n2 = 1
    print(n1)
    print(n2)
    for i in range(2, count):
        n2 = n1 + n2
        print(n2)
        n1 = n2 - n1

def main():
    fib(7)
    return

if __name__ == '__main__':
    main()
