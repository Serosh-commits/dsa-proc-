#include<bits/stdc++.h>
using namespace std;

void tarjan(int u, int& timer, vector<int> adj[], vector<int>& disc, vector<int>& low, stack<int>& st, vector<bool>& onStack) {
    disc[u] = low[u] = ++timer; st.push(u); onStack[u] = true;
    for(int v : adj[u]) {
        if(!disc[v]) { tarjan(v, timer, adj, disc, low, st, onStack); low[u] = min(low[u], low[v]); }
        else if(onStack[v]) low[u] = min(low[u], disc[v]);
    }
    if(low[u] == disc[u]) { while(true) { int v = st.top(); st.pop(); onStack[v] = false; if(u == v) break; } }
}

int main() {
    int V = 5, timer = 0; vector<int> adj[V], disc(V, 0), low(V, 0); stack<int> st; vector<bool> onStack(V, false);
    for(int i = 0; i < V; i++) if(!disc[i]) tarjan(i, timer, adj, disc, low, st, onStack);
    return 0;
}
