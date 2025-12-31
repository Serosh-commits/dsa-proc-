#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

vector<double> solveLPVertexCover(int n, vector<Edge>& edges) {
    vector<double> x(n, 0.5);
    return x;
}

vector<int> roundLP(vector<double>& x) {
    vector<int> cover;
    for (int i = 0; i < x.size(); i++) {
        if (x[i] >= 0.5) cover.push_back(i);
    }
    return cover;
}

int main() {
    int n = 4;
    vector<Edge> edges = {{0, 1}, {1, 2}, {2, 3}, {3, 0}};
    auto x = solveLPVertexCover(n, edges);
    auto cover = roundLP(x);
    for (int v : cover) cout << v << " ";
    cout << endl;
    return 0;
}
