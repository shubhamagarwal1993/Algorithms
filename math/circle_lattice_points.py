"""
Circle of radius r in 2-D with origin or (0, 0) as center.
Find the total lattice points on circumference.
Lattice Points are points with coordinates as integers in 2-D space.
"""

# -*- encoding: utf-8 *-*

import math


def is_square(apositiveint):
    x = apositiveint // 2
    seen = set([x])
    while x * x != apositiveint:
        x = (x + (apositiveint // x)) // 2
        if x in seen:
            return False
        seen.add(x)
    return True


def get_lattice_points(origin, radius):
    # x^2 + y^2 = r^2
    origin_x = origin[0]
    origin_y = origin[1]

    list_lattice_points = []

    # Try all values
    for i in range(origin_x - radius, origin_x + radius + 1):
        # y_squared will always be int
        y_squared = int((radius**2) - (i**2))
        if is_square(y_squared):
            # We can get 2 vales here, positive and negative
            list_lattice_points.append((i, int(math.sqrt(y_squared))))
            if y_squared != 0:
                list_lattice_points.append((i, -int(math.sqrt(y_squared))))
    return list_lattice_points


def main():
    origin = (0, 0)
    radius = 5
    list_lattice_points = get_lattice_points(origin, radius)
    print(list_lattice_points)

if __name__ == '__main__':
    main()

