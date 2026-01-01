#include<bits/stdc++.h>
using namespace std;

struct Edge { int to, cap, flow, cost, rev; };
vector<Edge> adj[100]; int dist[100], parent[100], edge_idx[100];

bool spfa(int s, int t, int& flow, int& cost) {
    fill(dist, dist + 100, INT_MAX); dist[s] = 0;
    queue<int> q; q.push(s); vector<bool> in_queue(100, false); in_queue[s] = true;
    while(!q.empty()) {
        int u = q.front(); q.pop(); in_queue[u] = false;
        for(int i = 0; i < adj[u].size(); i++) {
            Edge& e = adj[u][i];
            if(e.cap - e.flow > 0 && dist[e.to] > dist[u] + e.cost) {
                dist[e.to] = dist[u] + e.cost; parent[e.to] = u; edge_idx[e.to] = i;
                if(!in_queue[e.to]) { q.push(e.to); in_queue[e.to] = true; }
            }
        }
    }
    if(dist[t] == INT_MAX) return false;
    int push = INT_MAX;
    for(int v = t; v != s; v = parent[v]) push = min(push, adj[parent[v]][edge_idx[v]].cap - adj[parent[v]][edge_idx[v]].flow);
    flow += push; cost += push * dist[t];
    for(int v = t; v != s; v = parent[v]) {
        Edge& e = adj[parent[v]][edge_idx[v]]; e.flow += push; adj[v][e.rev].flow -= push;
    }
    return true;
}

int main() {
    return 0;
}
