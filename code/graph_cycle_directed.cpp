#include<bits/stdc++.h>
using namespace std;

bool isCyclic(int u, vector<int> adj[], vector<bool>& vis, vector<bool>& stack) {
    vis[u] = stack[u] = true;
    for(int v : adj[u]) {
        if(!vis[v] && isCyclic(v, adj, vis, stack)) return true;
        else if(stack[v]) return true;
    }
    stack[u] = false; return false;
}

int main() {
    int V = 4; vector<int> adj[V]; vector<bool> vis(V, false), stack(V, false);
    return 0;
}
