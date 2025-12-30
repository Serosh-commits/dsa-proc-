#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge { int to, weight; };

void dijkstra(int n, int s, vector<vector<Edge>>& adj, vector<int>& d) {
    d.assign(n, INF);
    d[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    while (!pq.empty()) {
        int v = pq.top().second, d_v = pq.top().first;
        pq.pop();
        if (d_v != d[v]) continue;
        for (auto edge : adj[v]) {
            if (d[v] + edge.weight < d[edge.to]) {
                d[edge.to] = d[v] + edge.weight;
                pq.push({d[edge.to], edge.to});
            }
        }
    }
}

int main() {
    int n = 3;
    vector<vector<Edge>> adj(n);
    adj[0].push_back({1, 10}); adj[1].push_back({2, 20}); adj[2].push_back({0, -5});
    vector<int> h(n, 0);
    for (int i = 0; i < n; i++) {
        for (int v = 0; v < n; v++) {
            for (auto edge : adj[v]) h[edge.to] = min(h[edge.to], h[v] + edge.weight);
        }
    }
    for (int v = 0; v < n; v++) {
        for (auto& edge : adj[v]) edge.weight += h[v] - h[edge.to];
    }
    for (int i = 0; i < n; i++) {
        vector<int> d;
        dijkstra(n, i, adj, d);
        for (int j = 0; j < n; j++) cout << (d[j] == INF ? INF : d[j] + h[j] - h[i]) << " ";
        cout << endl;
    }
    return 0;
}
