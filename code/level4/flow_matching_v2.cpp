#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int to, cap, flow, rev;
};

vector<Edge> adj[1005];
int level[1005], ptr[1005];

void addEdge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, (int)adj[to].size()});
    adj[to].push_back({from, 0, 0, (int)adj[from].size() - 1});
}

bool bfs(int s, int t) {
    memset(level, -1, sizeof(level));
    level[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto& edge : adj[v]) {
            if(edge.cap - edge.flow > 0 && level[edge.to] == -1) {
                level[edge.to] = level[v] + 1;
                q.push(edge.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int t, int pushed) {
    if(pushed == 0) return 0;
    if(v == t) return pushed;
    for(int& cid = ptr[v]; cid < adj[v].size(); cid++) {
        auto& edge = adj[v][cid];
        int tr = edge.to;
        if(level[v] + 1 != level[tr] || edge.cap - edge.flow == 0) continue;
        int push = dfs(tr, t, min(pushed, edge.cap - edge.flow));
        if(push == 0) continue;
        edge.flow += push;
        adj[tr][edge.rev].flow -= push;
        return push;
    }
    return 0;
}

int dinic(int s, int t) {
    int flow = 0;
    while(bfs(s, t)) {
        memset(ptr, 0, sizeof(ptr));
        while(int pushed = dfs(s, t, INT_MAX)) flow += pushed;
    }
    return flow;
}

int main() {
    addEdge(0, 1, 10); addEdge(0, 2, 10); addEdge(1, 2, 2); addEdge(1, 3, 4); addEdge(1, 4, 8); addEdge(2, 4, 9); addEdge(3, 5, 10); addEdge(4, 3, 6); addEdge(4, 5, 10);
    cout << dinic(0, 5) << endl;
    return 0;
}
