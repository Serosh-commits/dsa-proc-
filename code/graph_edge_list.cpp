#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

int main() {
    vector<Edge> edges = {{0, 1, 10}, {1, 2, 20}, {2, 0, 30}};
    for (auto& e : edges) cout << e.u << " " << e.v << " " << e.w << endl;
    return 0;
}
