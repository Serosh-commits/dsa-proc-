#include <bits/stdc++.h>
using namespace std;

struct Graph {
    int V;
    vector<vector<int>> adj;
    int timer;
    vector<int> tin, low;
    stack<pair<int, int>> st;

    Graph(int v) : V(v), adj(v), timer(0), tin(v, -1), low(v, -1) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void findBCC(int u, int p = -1) {
        tin[u] = low[u] = timer++;
        for (int v : adj[u]) {
            if (v == p) continue;
            if (tin[v] != -1) {
                low[u] = min(low[u], tin[v]);
                if (tin[v] < tin[u]) st.push({u, v});
            } else {
                st.push({u, v});
                findBCC(v, u);
                low[u] = min(low[u], low[v]);
                if (low[v] >= tin[u]) {
                    cout << "BCC: ";
                    while (true) {
                        pair<int, int> edge = st.top(); st.pop();
                        cout << "(" << edge.first << "," << edge.second << ") ";
                        if (edge.first == u && edge.second == v) break;
                    }
                    cout << endl;
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    g.findBCC(0);
    return 0;
}
