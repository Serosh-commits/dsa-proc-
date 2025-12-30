#include <bits/stdc++.h>
using namespace std;

int main() {
    int V = 10;
    vector<vector<int>> adj(V);
    for (int i = 0; i < V - 1; i++) adj[i].push_back(i + 1);
    vector<int> dist(V, -1);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        #pragma omp parallel for
        for (int i = 0; i < adj[u].size(); i++) {
            int v = adj[u][i];
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << dist[V - 1] << endl;
    return 0;
}
