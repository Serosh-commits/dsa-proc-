#include<bits/stdc++.h>
using namespace std;

bool bfs(int s, int t, vector<int> adj[], int level[], int V) {
    memset(level, -1, sizeof(int) * V); level[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v : adj[u]) if(level[v] == -1) { level[v] = level[u] + 1; q.push(v); }
    }
    return level[t] != -1;
}

int main() {
    int V = 5; vector<int> adj[V]; int level[V];
    bfs(0, 4, adj, level, V);
    return 0;
}
