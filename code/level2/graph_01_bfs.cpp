#include<bits/stdc++.h>
using namespace std;

void zeroOneBFS(int s, vector<pair<int, int>> adj[], int V) {
    vector<int> dist(V, INT_MAX); deque<int> dq;
    dist[s] = 0; dq.push_back(s);
    while(!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for(auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if(w == 0) dq.push_front(v); else dq.push_back(v);
            }
        }
    }
}

int main() {
    int V = 5; vector<pair<int, int>> adj[V];
    zeroOneBFS(0, adj, V);
    return 0;
}
