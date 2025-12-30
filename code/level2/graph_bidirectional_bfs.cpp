#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    Graph(int v) : V(v), adj(v) {}
    void addEdge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }

    int bidirectionalBFS(int s, int t) {
        if (s == t) return 0;
        queue<int> q1, q2;
        vector<int> dist1(V, -1), dist2(V, -1);

        q1.push(s); dist1[s] = 0;
        q2.push(t); dist2[t] = 0;

        while (!q1.empty() && !q2.empty()) {

            int u = q1.front(); q1.pop();
            for (int v : adj[u]) {
                if (dist1[v] == -1) {
                    dist1[v] = dist1[u] + 1;
                    if (dist2[v] != -1) return dist1[v] + dist2[v];
                    q1.push(v);
                }
            }

            u = q2.front(); q2.pop();
            for (int v : adj[u]) {
                if (dist2[v] == -1) {
                    dist2[v] = dist2[u] + 1;
                    if (dist1[v] != -1) return dist1[v] + dist2[v];
                    q2.push(v);
                }
            }
        }
        return -1;
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1); g.addEdge(1, 2); g.addEdge(2, 3);
    g.addEdge(3, 4); g.addEdge(4, 5);
    cout << "Shortest path 0 to 5: " << g.bidirectionalBFS(0, 5) << endl;
    return 0;
}
