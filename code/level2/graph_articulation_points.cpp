#include<bits/stdc++.h>
using namespace std;

void findAPs(int u, int p, int& timer, vector<int> adj[], vector<int>& disc, vector<int>& low, vector<bool>& ap) {
    disc[u] = low[u] = ++timer; int children = 0;
    for(int v : adj[u]) {
        if(v == p) continue;
        if(disc[v]) low[u] = min(low[u], disc[v]);
        else {
            children++; findAPs(v, u, timer, adj, disc, low, ap);
            low[u] = min(low[u], low[v]);
            if(p != -1 && low[v] >= disc[u]) ap[u] = true;
        }
    }
    if(p == -1 && children > 1) ap[u] = true;
}

int main() {
    int V = 5, timer = 0; vector<int> adj[V], disc(V, 0), low(V, 0); vector<bool> ap(V, false);
    findAPs(0, -1, timer, adj, disc, low, ap);
    return 0;
}
