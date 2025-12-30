#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int u, int p, vector<int> adj[], vector<bool>& vis) {
    vis[u] = true;
    for(int v : adj[u]) {
        if(!vis[v]) { if(isCyclic(v, u, adj, vis)) return true; }
        else if(v != p) return true;
    }
    return false;
}

int main() {
    int V = 4; vector<int> adj[V]; vector<bool> vis(V, false);
    return 0;
}
