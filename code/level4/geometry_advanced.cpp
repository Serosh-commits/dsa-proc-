#include<bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

int cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

vector<Point> convex_hull(vector<Point>& points) {
    int n = points.size(), k = 0;
    if(n <= 3) return points;
    vector<Point> hull(2 * n);
    sort(points.begin(), points.end());
    for(int i = 0; i < n; i++) {
        while(k >= 2 && cross_product(hull[k-2], hull[k-1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && cross_product(hull[k-2], hull[k-1], points[i]) <= 0) k--;
        hull[k++] = points[i];
    }
    hull.resize(k - 1);
    return hull;
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    vector<Point> hull = convex_hull(points);
    for(auto p : hull) cout << "(" << p.x << ", " << p.y << ") ";
    return 0;
}
