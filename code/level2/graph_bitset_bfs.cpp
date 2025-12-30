#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000;

struct Graph {
    int V;
    vector<bitset<MAXV>> adj;

    Graph(int v) : V(v), adj(v) {}

    void addEdge(int u, int v) {
        adj[u].set(v);
        adj[v].set(u);
    }

    void bfs(int s) {
        vector<int> dist(V, -1);
        bitset<MAXV> visited;
        queue<int> q;

        q.push(s);
        dist[s] = 0;
        visited.set(s);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (int v = 0; v < V; v++) {
                if (adj[u].test(v) && !visited.test(v)) {
                    visited.set(v);
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        cout << "BFS from " << s << " completed." << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1); g.addEdge(0, 2); g.addEdge(1, 3); g.addEdge(2, 4);
    g.bfs(0);
    return 0;
}
