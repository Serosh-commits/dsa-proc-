#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, w;
};

void bellmanFord(int n, int start, vector<Edge>& edges) {
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;
    for(int i = 1; i < n; i++) {
        for(auto& e : edges) {
            if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
            }
        }
    }
    for(auto& e : edges) {
        if(dist[e.u] != INT_MAX && dist[e.u] + e.w < dist[e.v]) {
            cout << "Negative cycle detected" << endl;
            return;
        }
    }
}

int main() {
    int n = 5;
    vector<Edge> edges = {{0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}};
    bellmanFord(n, 0, edges);
    return 0;
}
