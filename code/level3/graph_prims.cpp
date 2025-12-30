#include<bits/stdc++.h>
using namespace std;

void prim(int V, vector<pair<int, int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> key(V, INT_MAX); vector<bool> inMST(V, false);
    pq.push({0, 0}); key[0] = 0;
    while(!pq.empty()) {
        int u = pq.top().second; pq.pop(); inMST[u] = true;
        for(auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if(!inMST[v] && key[v] > w) { key[v] = w; pq.push({key[v], v}); }
        }
    }
}

int main() {
    int V = 5; vector<pair<int, int>> adj[V];
    prim(V, adj);
    return 0;
}
