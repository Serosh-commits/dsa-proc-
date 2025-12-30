#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<pair<int, int>>> adj;
    Graph(int v) : V(v), adj(v) {}
    void addEdge(int u, int v, int w) { adj[u].push_back({v, w}); }
};

int main() {
    Graph g(3);
    g.addEdge(0, 1, 10); g.addEdge(1, 2, 20);
    for (int i = 0; i < 3; i++) {
        for (auto& e : g.adj[i]) cout << i << "->" << e.first << " (" << e.second << ") ";
        cout << endl;
    }
    return 0;
}
