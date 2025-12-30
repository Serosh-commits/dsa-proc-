#include<bits/stdc++.h>
using namespace std;

void kahn(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0); for(int i = 0; i < V; i++) for(int v : adj[i]) inDegree[v]++;
    queue<int> q; for(int i = 0; i < V; i++) if(inDegree[i] == 0) q.push(i);
    while(!q.empty()) { int u = q.front(); q.pop(); for(int v : adj[u]) if(--inDegree[v] == 0) q.push(v); }
}

int main() {
    int V = 5; vector<int> adj[V];
    kahn(V, adj);
    return 0;
}
