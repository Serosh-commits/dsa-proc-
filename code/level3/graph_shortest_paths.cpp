#include<bits/stdc++.h>
using namespace std;

void dijkstra(int start, vector<vector<pair<int, int>>>& adj) {
    int n = adj.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    while(!pq.empty()) {
        int d = pq.top().first, u = pq.top().second; pq.pop();
        if(d > dist[u]) continue;
        for(auto& edge : adj[u]) {
            int v = edge.first, w = edge.second;
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    for(int i = 0; i < n; i++) cout << dist[i] << " ";
}

void floydWarshall(vector<vector<int>>& dist, int n) {
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 5}); adj[0].push_back({2, 10});
    adj[1].push_back({2, 3}); adj[1].push_back({3, 20});
    adj[2].push_back({3, 2});
    dijkstra(0, adj); cout << endl;
    return 0;
}
