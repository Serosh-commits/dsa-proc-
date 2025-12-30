#include<bits/stdc++.h>
using namespace std;

void bfs(int s, vector<int> adj[], int V) {
    vector<int> dist(V, -1); queue<int> q;
    dist[s] = 0; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) if(dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
    }
}

int main() {
    int V = 5; vector<int> adj[V];
    bfs(0, adj, V);
    return 0;
}
