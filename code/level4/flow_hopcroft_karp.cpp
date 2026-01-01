#include<bits/stdc++.h>
using namespace std;

const int NIL = 0, INF = INT_MAX;
vector<int> adj[100]; int pairU[100], pairV[100], dist[100];

bool bfs(int n, int m) {
    queue<int> q;
    for(int u = 1; u <= n; u++) if(pairU[u] == NIL) { dist[u] = 0; q.push(u); } else dist[u] = INF;
    dist[NIL] = INF;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        if(dist[u] < dist[NIL]) for(int v : adj[u]) if(dist[pairV[v]] == INF) { dist[pairV[v]] = dist[u] + 1; q.push(pairV[v]); }
    }
    return dist[NIL] != INF;
}

bool dfs(int u) {
    if(u != NIL) {
        for(int v : adj[u]) if(dist[pairV[v]] == dist[u] + 1) if(dfs(pairV[v])) { pairV[v] = u; pairU[u] = v; return true; }
        dist[u] = INF; return false;
    }
    return true;
}

int main() {
    return 0;
}
