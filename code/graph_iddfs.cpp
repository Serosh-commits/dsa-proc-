#include<bits/stdc++.h>
using namespace std;

bool dls(int u, int target, int limit, vector<int> adj[]) {
    if(u == target) return true;
    if(limit <= 0) return false;
    for(int v : adj[u]) if(dls(v, target, limit - 1, adj)) return true;
    return false;
}

int main() {
    int V = 5; vector<int> adj[V];
    for(int i = 0; i < 10; i++) if(dls(0, 4, i, adj)) break;
    return 0;
}
