#include<bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };

void bellmanFord(int n, int start, vector<Edge>& edges) {
    vector<int> dist(n, INT_MAX); dist[start] = 0;
    for(int i = 1; i < n; i++) {
        for(auto& e : edges) if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) dist[e.v] = dist[e.u] + e.w;
    }
}

int main() {
    int n = 5; vector<Edge> edges;
    bellmanFord(n, 0, edges);
    return 0;
}
