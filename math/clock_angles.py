"""
Given hour and minute, write a function to calculate an angle between hour/minute hand

Note that a clock is a circle made of 360 degrees, and that each number represents an angle
and the separation between them is 360/12 = 30.

E.g. At 2:00, the minute hand is on the 12 and the hour hand is on the 2.
The correct answer is 2 * 30 = 60 degrees

Input:  h = 12:00, m = 30.00
Output: 165 degree

Input:  h = 3.00, m = 30.00
Output: 75 degree
"""

# -*- coding: utf-8 -*-

import math


def find_angle(hour, minute):
    if hour < 0 or hour > 12 or minute < 0 or minute > 60:
        return -1
    if hour == 12:
        hour = 0
    if minute == 60:
        minute = 0
    """
    The minute hand moves 360 degree in 60 minute(or 6 degree in one min)
    The hour hand moves 360 degres in 12 hours (or 0.5 degree in 1 min)

    All calculations with reference to 12:00
    """
    min_pos = minute * 6

    total_mins = (hour * 60) + minute
    hour_pos = total_mins * 0.5

    angle = int(abs(min_pos - hour_pos))
    return min(angle, 360 - angle)


def main():
    hour = 3
    min = 30
    angle = find_angle(hour, min)
    print("angle between", hour, "and", min, "is", angle)

if __name__ == '__main__':
    main()

