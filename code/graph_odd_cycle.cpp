#include<bits/stdc++.h>
using namespace std;

bool hasOddCycle(int u, int c, vector<int> adj[], vector<int>& color) {
    color[u] = c;
    for(int v : adj[u]) {
        if(color[v] == -1) { if(hasOddCycle(v, 1 - c, adj, color)) return true; }
        else if(color[v] == c) return true;
    }
    return false;
}

int main() {
    int V = 4; vector<int> adj[V]; vector<int> color(V, -1);
    return 0;
}
