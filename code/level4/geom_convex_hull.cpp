#include<bits/stdc++.h>
using namespace std;

struct Point { int x, y; };
int orientation(Point p, Point q, Point r) {
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if(val == 0) return 0; return (val > 0) ? 1 : 2;
}

void convexHull(vector<Point>& points) {
    int n = points.size(); if(n < 3) return;
    int l = 0; for(int i = 1; i < n; i++) if(points[i].x < points[l].x) l = i;
    int p = l, q;
    do {
        cout << "(" << points[p].x << ", " << points[p].y << ")\n";
        q = (p + 1) % n;
        for(int i = 0; i < n; i++) if(orientation(points[p], points[i], points[q]) == 2) q = i;
        p = q;
    } while(p != l);
}

int main() {
    vector<Point> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
    convexHull(points);
    return 0;
}
