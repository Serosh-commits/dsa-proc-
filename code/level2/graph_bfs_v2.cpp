#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    queue<int> q;
    visited[s] = true; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        cout << u << " ";
        for(int v : adj[u]) if(!visited[v]) { visited[v] = true; q.push(v); }
    }
}

int main() {
    int V = 5; vector<int> adj[V];
    bfs(0, adj, V);
    return 0;
}
