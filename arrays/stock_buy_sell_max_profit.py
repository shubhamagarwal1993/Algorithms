"""
Cost of a stock on each day is given in a list.
Find the max profit that you can make by buying and selling in those days.

E.g.
For [100, 180, 260, 310, 40, 535, 695], the max profit can earned by:
 - buy on day 0
 - sell on day 3
 - buy on day 4
 - sell on day 6

If given prices are sorted in decreasing order, then profit cannot be earned at all
"""

# -*- encoding: utf-8 *-*

import math
import functools


def printSell(day):
    print("Sell on day ", day)


def printBuy(day):
    print("buy on day ", day)


def buySellMultipleOrders(input):
    if len(input) < 2:
        print("Cannot have less than 2 day stock data")
        return

    """
        loop from 1st position, checking prev price
        input   [100, 180, 260, 310, 40, 535, 695]
        day      0    1    2    3    4   5    6

        5 cases:
        if last item of array, have to sell
        if already bought and curr_price > prev_price
        if already bought and curr_price < prev_price
        if not bought and curr_price > prev_price
        if not bought and curr_price < prev_price
    """
    already_bought = False
    for i in range(1, len(input)):
        curr_price = input[i]
        prev_price = input[i-1]
        # sell on last day
        if i == len(input) - 1 and already_bought:
            printSell(i)
            already_bought = False
        elif not already_bought and curr_price < prev_price:
            pass
        elif not already_bought and curr_price > prev_price:
            printBuy(i - 1)
            already_bought = True
        elif already_bought and curr_price > prev_price:
            pass
        elif already_bought and curr_price < prev_price:
            printSell(i - 1)
            already_bought = False
            pass


def buySellSingleOrder(input):
    if len(input) < 2:
        print("Cannot have less than 2 day stock data")
        return

    """
        loop from 1st position, checking prev price
        input   [100, 180, 260, 310, 40, 535, 695]
        day      0    1    2    3    4   5    6

        5 cases:
        if last item of array, have to sell
        if already bought and curr_price > prev_price
        if already bought and curr_price < prev_price
        if not bought and curr_price > prev_price
        if not bought and curr_price < prev_price
    """
    already_bought = False
    # Price at which stock was bought
    buy_price = 0

    # Profit comparison
    max_profit = 0
    curr_profit = 0

    buy_day = -1
    sell_day = -1

    for i in range(1, len(input)):

        curr_price = input[i]
        prev_price = input[i-1]

        # sell on last day
        if i == len(input) - 1 and already_bought:
            curr_profit = curr_price - buy_price
            if curr_profit > max_profit:
                max_profit = curr_profit
            sell_day = i
            already_bought = False
        elif not already_bought and curr_price < prev_price:
            pass
        elif not already_bought and curr_price > prev_price:
            buy_price = prev_price
            buy_day = i - 1
            already_bought = True
        elif already_bought and curr_price > prev_price:
            pass
        elif already_bought and curr_price < prev_price:
            curr_profit = prev_price - buy_price
            if curr_profit > max_profit:
                max_profit = curr_profit
            sell_day = i - 1
            already_bought = False
            pass

    print("Buy on day ", buy_day, " and sell on day ", sell_day, " for max profit of ", max_profit)


def main():
    input = [100, 180, 260, 310, 40, 535, 695]
    buySellMultipleOrders(input)
    buySellSingleOrder(input)

if __name__ == '__main__':
    main()

