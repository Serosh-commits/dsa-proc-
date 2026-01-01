#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Edge {
    int to, cap, flow, rev;
};

vector<Edge> adj[105];
int level[105], ptr[105];

void add_edge(int from, int to, int cap) {
    adj[from].push_back({to, cap, 0, (int)adj[to].size()});
    adj[to].push_back({from, cap, 0, (int)adj[from].size() - 1});
}

bool bfs(int s, int t) {
    fill(level, level + 105, -1);
    level[s] = 0;
    queue<int> q; q.push(s);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto& e : adj[v]) {
            if(e.cap - e.flow > 0 && level[e.to] == -1) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
    return level[t] != -1;
}

int dfs(int v, int t, int pushed) {
    if(pushed == 0) return 0;
    if(v == t) return pushed;
    for(int& cid = ptr[v]; cid < adj[v].size(); ++cid) {
        auto& e = adj[v][cid];
        int tr = e.to;
        if(level[v] + 1 != level[tr] || e.cap - e.flow == 0) continue;
        int tr_pushed = dfs(tr, t, min(pushed, e.cap - e.flow));
        if(tr_pushed == 0) continue;
        e.flow += tr_pushed;
        adj[tr][e.rev].flow -= tr_pushed;
        return tr_pushed;
    }
    return 0;
}

int dinic(int s, int t, int n) {
    int flow = 0;
    while(bfs(s, t)) {
        fill(ptr, ptr + 105, 0);
        while(int pushed = dfs(s, t, INF)) flow += pushed;
    }
    return flow;
}

struct GHEdge {
    int u, v, w;
};

void build_gomory_hu(int n, vector<GHEdge>& tree) {
    vector<int> p(n, 0);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) for(auto& e : adj[j]) e.flow = 0;
        int f = dinic(i, p[i], n);
        tree.push_back({i, p[i], f});
        vector<bool> vis(n, false);
        queue<int> q; q.push(i); vis[i] = true;
        while(!q.empty()) {
            int v = q.front(); q.pop();
            for(auto& e : adj[v]) if(e.cap - e.flow > 0 && !vis[e.to]) { vis[e.to] = true; q.push(e.to); }
        }
        for(int j = i + 1; j < n; j++) if(vis[j] && p[j] == p[i]) p[j] = i;
    }
}

int main() {
    int n = 4;
    add_edge(0, 1, 10);
    add_edge(0, 2, 5);
    add_edge(1, 2, 15);
    add_edge(1, 3, 10);
    add_edge(2, 3, 10);

    vector<GHEdge> tree;
    build_gomory_hu(n, tree);
    for(auto& e : tree) cout << e.u << " - " << e.v << " : " << e.w << endl;
    return 0;
}
