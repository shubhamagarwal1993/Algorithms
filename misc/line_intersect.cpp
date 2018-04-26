#include <iostream>

using namespace std;

class Point {
    private:
        int x;
        int y;
    public:
        Point() : x(0), y(0) {}
        Point(int x, int y) : x(x), y(y) {}

        int getX() {
            return this->x;
        }
        int getY() {
            return this->y;
        }
};

class Line {
    private:
        Point start;
        Point end;
    public:
        Line() : start(0, 0), end(0, 0) {}
        Line(Point start, Point end) : start(start), end(end) {}

        // TODO: handle infinite slope with delta X is 0
        double getSlope() {
            return (end.getY() - start.getY())/(end.getX() - start.getX());
        }
        int getYIntercept() {
            return end.getY() - (getSlope() * end.getX());
        }
};

bool pointOnLine(Line line, Point start) {
    int y = line.getSlope() * start.getX() + line.getYIntercept();
    if (y == start.getY()) {
        return true;
    } else {
        return false;
    }
}

Point getIntersection(Point start1, Point end1, Point start2, Point end2) {
    // Rearrange points so start is before end, and start1 is before start2
    if(start1.getX() > end1.getX()) swap(start1, end1);
    if(start2.getX() > end2.getX()) swap(start2, end2);
    if(start1.getX() > start2.getX()) {
        swap(start1, start2);
        swap(end1, end2);
    }

    // compute lines
    Line line1(start1, end1);
    Line line2(start2, end2);

    // check for parallel lines and if they intersect
    if(line1.getSlope() == line2.getSlope()) {
        if( (line1.getYIntercept() == line2.getYIntercept()) 
         && (pointOnLine(line1, start2)) ) {
            cout << "Lines intersect on " << start2.getX() << " " << start2.getY() << endl;
            return start2;
        }
        cout << "Lines do not intersect" << endl;
        return start2;
    }

    // Get intersection coordinates - this is assuming the lines intersect
    // Let line1 have equation y1 = m1x1 + c1 and line2 have equation y2 = m2x2 + c2
    // y1 = y2 and x1 = x2 for point of intersection, thus m1x + c1 = m2x + c2 => x = (c2 - c1) / (m1 - m2)
    int intersection_x = (line2.getYIntercept() - line1.getYIntercept()) / (line1.getSlope() - line2.getSlope());
    int intersection_y = line1.getSlope() * intersection_x + line1.getYIntercept();
    Point intersection(intersection_x, intersection_y);

    // check if this point actually lies on both the lines
    if(pointOnLine(line1, intersection) && pointOnLine(line2, intersection)) {
        cout << "Lines intersect on " << intersection.getX() << " " << intersection.getY() << endl;
        return intersection;
    } else {
        cout << "Lines do not intersect" << endl;
        return start2;
    }
}

int main() {

    Point start1(-2, 0);
    Point end1(2, 0);
    Point start2(-1, -1);
    Point end2(1, 1);

    getIntersection(start1, end1, start2, end2);
	return 0;
}

