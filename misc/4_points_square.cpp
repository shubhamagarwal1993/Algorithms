#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

bool isSquare(Point a, Point b, Point c, Point d) {
    int dist_arr[6];

    dist_arr[0] = ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
    dist_arr[1]  = ((a.x - c.x) * (a.x - c.x)) + ((a.y - c.y) * (a.y - c.y));
    dist_arr[2]  = ((a.x - d.x) * (a.x - d.x)) + ((a.y - d.y) * (a.y - d.y));
    dist_arr[3]  = ((b.x - c.x) * (b.x - c.x)) + ((b.y - c.y) * (b.y - c.y));
    dist_arr[4]  = ((b.x - d.x) * (b.x - d.x)) + ((b.y - d.y) * (b.y - d.y));
    dist_arr[5]  = ((c.x - d.x) * (c.x - d.x)) + ((c.y - d.y) * (c.y - d.y));

    sort(dist_arr, dist_arr + 6);

    // all 4 sides have to be equal
    // all 2 diagonals have to be equal
    if(!((dist_arr[0] == dist_arr[1])
      && (dist_arr[1] == dist_arr[2])
      && (dist_arr[2] == dist_arr[3])
      && (dist_arr[0] == dist_arr[3])
      )) {
        return false;
    }

    if(!((dist_arr[4] == dist_arr[5]))) {
        return false;
    }

    return true;
}

int main() {
	Point a = {1, 5};
    Point b = {4, 8};
    Point c = {4, 5};
    Point d = {1, 8};

    if(isSquare(a, b, c, d)) {
        cout << "Is a square" << endl;
    } else {
        cout << "Not a square" << endl;
    }

	return 0;
}

