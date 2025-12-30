#include<bits/stdc++.h>
using namespace std;

void dfs1(int u, vector<int> adj[], vector<bool>& vis, stack<int>& st) {
    vis[u] = true; for(int v : adj[u]) if(!vis[v]) dfs1(v, adj, vis, st); st.push(u);
}
void dfs2(int u, vector<int> revAdj[], vector<bool>& vis) {
    vis[u] = true; for(int v : revAdj[u]) if(!vis[v]) dfs2(v, revAdj, vis);
}

int main() {
    int V = 5; vector<int> adj[V], revAdj[V]; vector<bool> vis(V, false); stack<int> st;
    for(int i = 0; i < V; i++) if(!vis[i]) dfs1(i, adj, vis, st);
    vis.assign(V, false);
    while(!st.empty()) { int u = st.top(); st.pop(); if(!vis[u]) dfs2(u, revAdj, vis); }
    return 0;
}
