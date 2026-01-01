#include<bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

struct QState {
    vector<double> amplitudes;
    int n;
    QState(int _n) : n(_n) {
        amplitudes.assign(1 << n, 0.0);
        amplitudes[0] = 1.0;
    }
};

void applyGrover(QState& state, int target) {
    double avg = 0;
    for(double a : state.amplitudes) avg += a;
    avg /= state.amplitudes.size();
    for(double& a : state.amplitudes) a = 2 * avg - a;
}

double solveQuantumClosestPair(vector<Point>& pts) {
    int n = pts.size();
    if(n <= 1) return 1e18;
    sort(pts.begin(), pts.end(), [](Point a, Point b) {
        return a.x < b.x;
    });
    double d = 1e18;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n && (pts[j].x - pts[i].x) < d; j++) {
            d = min(d, dist(pts[i], pts[j]));
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n = 10;
    vector<Point> pts(n);
    for(int i = 0; i < n; i++) pts[i] = { (double)(rand() % 100), (double)(rand() % 100) };
    cout << fixed << setprecision(6) << solveQuantumClosestPair(pts) << endl;
    return 0;
}
