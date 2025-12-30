#include<bits/stdc++.h>
using namespace std;

void findBridges(int u, int p, int& timer, vector<int> adj[], vector<int>& disc, vector<int>& low) {
    disc[u] = low[u] = ++timer;
    for(int v : adj[u]) {
        if(v == p) continue;
        if(disc[v]) low[u] = min(low[u], disc[v]);
        else {
            findBridges(v, u, timer, adj, disc, low);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u]) cout << u << "-" << v << " is a bridge" << endl;
        }
    }
}

int main() {
    int V = 5, timer = 0; vector<int> adj[V], disc(V, 0), low(V, 0);
    findBridges(0, -1, timer, adj, disc, low);
    return 0;
}
