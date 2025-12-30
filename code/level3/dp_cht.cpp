#include<bits/stdc++.h>
using namespace std;

struct Line {
    long long m, c;
    long long eval(long long x) { return m * x + c; }
};

struct CHT {
    vector<Line> lines;
    void addLine(long long m, long long c) { lines.push_back({m, c}); }
    long long query(long long x) {
        long long res = LLONG_MAX;
        for(auto& l : lines) res = min(res, l.eval(x));
        return res;
    }
};

int main() {
    CHT cht; cht.addLine(1, 0);
    return 0;
}
