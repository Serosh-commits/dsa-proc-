#include<bits/stdc++.h>
using namespace std;

void iterativeDFS(int s, vector<int> adj[], int V) {
    vector<bool> visited(V, false); stack<int> st;
    st.push(s);
    while(!st.empty()) {
        int u = st.top(); st.pop();
        if(!visited[u]) { visited[u] = true; cout << u << " "; }
        for(int v : adj[u]) if(!visited[v]) st.push(v);
    }
}

int main() {
    int V = 5; vector<int> adj[V];
    iterativeDFS(0, adj, V);
    return 0;
}
