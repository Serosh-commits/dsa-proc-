#include <bits/stdc++.h>
using namespace std;

struct Point { double x, y; };

double distSq(Point a, Point b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main() {
    vector<Point> points = {{0, 0}, {5, 5}, {0, 10}, {10, 0}};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            Point p = {(double)i, (double)j};
            int best = 0;
            for (int k = 1; k < points.size(); k++) {
                if (distSq(p, points[k]) < distSq(p, points[best])) best = k;
            }
            cout << best << " ";
        }
        cout << endl;
    }
    return 0;
}
