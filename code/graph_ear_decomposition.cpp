#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    vector<bool> visited;
    vector<int> parent;

    Graph(int v) : V(v), adj(v), visited(v, false), parent(v, -1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findEars(int u, int p = -1) {
        visited[u] = true;
        parent[u] = p;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (visited[v]) {

                cout << "Ear: " << v << " ";
                int curr = u;
                while (curr != v && curr != -1) {
                    cout << curr << " ";
                    curr = parent[curr];
                }
                cout << v << endl;
            } else {
                findEars(v, u);
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1); g.addEdge(1, 2); g.addEdge(2, 0); g.addEdge(2, 3); g.addEdge(3, 0);
    g.findEars(0);
    return 0;
}
