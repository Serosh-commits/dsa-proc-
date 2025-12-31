#include <bits/stdc++.h>
using namespace std;

struct PostQuantumGeom {
    struct Point { double x, y; };
    vector<Point> points;
    void addPoint(double x, double y) { points.push_back({x, y}); }
};

int main() {
    PostQuantumGeom pqg;
    pqg.addPoint(1.0, 2.0);
    return 0;
}
