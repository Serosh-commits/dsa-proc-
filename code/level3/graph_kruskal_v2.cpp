#include<bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; bool operator<(const Edge& other) const { return w < other.w; } };
struct DSU {
    vector<int> p; DSU(int n) { p.resize(n); iota(p.begin(), p.end(), 0); }
    int find(int i) { return p[i] == i ? i : p[i] = find(p[i]); }
    void unite(int i, int j) { int r1 = find(i), r2 = find(j); if(r1 != r2) p[r1] = r2; }
};

int main() {
    int V = 4; vector<Edge> edges = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    sort(edges.begin(), edges.end()); DSU dsu(V); int mst = 0;
    for(auto& e : edges) if(dsu.find(e.u) != dsu.find(e.v)) { dsu.unite(e.u, e.v); mst += e.w; }
    cout << mst << endl;
    return 0;
}
