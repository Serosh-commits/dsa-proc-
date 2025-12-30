#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V, E;
    vector<vector<int>> mat;
    Graph(int v, int e) : V(v), E(e), mat(v, vector<int>(e, 0)) {}
    void addEdge(int edgeIdx, int u, int v) {
        mat[u][edgeIdx] = 1;
        mat[v][edgeIdx] = 1;
    }
};

int main() {
    Graph g(3, 2);
    g.addEdge(0, 0, 1);
    g.addEdge(1, 1, 2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) cout << g.mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
