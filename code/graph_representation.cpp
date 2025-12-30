#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int v) : V(v), adj(v) {}
    void addEdge(int u, int v) { adj[u].push_back(v); }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(1, 2); g.addEdge(2, 3);
    for (int i = 0; i < 4; i++) {
        cout << i << ": ";
        for (int v : g.adj[i]) cout << v << " ";
        cout << endl;
    }
    return 0;
}
