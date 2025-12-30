#include<bits/stdc++.h>
using namespace std;

void dfsUtil(int u, vector<int> adj[], vector<bool>& visited) {
    visited[u] = true; cout << u << " ";
    for(int v : adj[u]) if(!visited[v]) dfsUtil(v, adj, visited);
}

void dfs(vector<int> adj[], int V) {
    vector<bool> visited(V, false);
    for(int i = 0; i < V; i++) if(!visited[i]) dfsUtil(i, adj, visited);
}

int main() {
    int V = 5; vector<int> adj[V];
    dfs(adj, V);
    return 0;
}
