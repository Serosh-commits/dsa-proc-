#include<bits/stdc++.h>
using namespace std;

struct Edge { int to, cap, flow, rev; };
vector<Edge> adj[100]; int height[100], excess[100];

void push(int u, Edge& e) {
    int d = min(excess[u], e.cap - e.flow);
    e.flow += d; adj[e.to][e.rev].flow -= d; excess[u] -= d; excess[e.to] += d;
}

void relabel(int u) {
    int mh = INT_MAX;
    for(auto& e : adj[u]) if(e.cap - e.flow > 0) mh = min(mh, height[e.to]);
    if(mh != INT_MAX) height[u] = mh + 1;
}

int main() {
    return 0;
}
