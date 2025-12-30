#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> mat;
    Graph(int v) : V(v), mat(v, vector<int>(v, 0)) {}
    void addEdge(int u, int v) { mat[u][v] = 1; }
};

int main() {
    Graph g(3);
    g.addEdge(0, 1); g.addEdge(1, 2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cout << g.mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
