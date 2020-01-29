"""
Using basic datetime library of python3

E.g. 2019-08-06T12:30:00-07:00
Extract 2019, 08, 06 seperately from this
"""

# -*- encoding: utf-8 *-*

from datetime import datetime


def print_datetime_info(datetime_object):
    print("Year - ", datetime_object.year)
    print("Month - ", datetime_object.month)
    print("Day - ", datetime_object.day)
    print("Hour - ", datetime_object.hour)
    print("Min - ", datetime_object.minute)
    print("Sec - ", datetime_object.second)
    return


def main():
    # If you have datetime as an string
    datetime_str = datetime.strptime("2019-08-06T12:30:00-07:00", "%Y-%m-%dT%H:%M:%S%z")
    print_datetime_info(datetime_str)

    # If you have datetime as an object
    datetime_obj = datetime.now()
    print_datetime_info(datetime_str)

    return


if __name__ == '__main__':
    main()

