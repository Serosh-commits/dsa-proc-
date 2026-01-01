#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

struct Triangle {
    int a, b, c;
};

bool isDelaunay(Point p, Point a, Point b, Point c) {
    double adx = a.x - p.x, ady = a.y - p.y;
    double bdx = b.x - p.x, bdy = b.y - p.y;
    double cdx = c.x - p.x, cdy = c.y - p.y;
    double ab = adx * bdy - bdx * ady;
    double bc = bdx * cdy - cdx * bdy;
    double ca = cdx * ady - adx * cdy;
    double al = adx * adx + ady * ady;
    double bl = bdx * bdx + bdy * bdy;
    double cl = cdx * cdx + cdy * cdy;
    return (al * bc + bl * ca + cl * ab) > 0;
}

int main() {
    vector<Point> points = {{0, 0}, {10, 0}, {0, 10}, {5, 5}};
    cout << "Delaunay triangulation check: " << isDelaunay(points[3], points[0], points[1], points[2]) << endl;
    return 0;
}
