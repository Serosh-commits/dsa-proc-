#include<bits/stdc++.h>
using namespace std;

void topoSortUtil(int u, vector<int> adj[], vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for(int v : adj[u]) if(!visited[v]) topoSortUtil(v, adj, visited, st);
    st.push(u);
}

int main() {
    int V = 4; vector<int> adj[V]; vector<bool> visited(V, false); stack<int> st;
    for(int i = 0; i < V; i++) if(!visited[i]) topoSortUtil(i, adj, visited, st);
    return 0;
}
