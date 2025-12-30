#include<bits/stdc++.h>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& adj, int V) {
    vector<int> dist(V, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();
        if(d > dist[u]) continue;
        for(auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if(dist[u] + w < dist[v]) { dist[v] = dist[u] + w; pq.push({dist[v], v}); }
        }
    }
}

int main() {
    int V = 5; vector<vector<pair<int, int>>> adj(V);
    dijkstra(0, adj, V);
    return 0;
}
