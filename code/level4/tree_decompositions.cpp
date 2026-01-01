#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], sz[MAXN], son[MAXN], top[MAXN], id[MAXN], cnt;

void dfs1(int u, int f, int d) {
    parent[u] = f; depth[u] = d; sz[u] = 1;
    for(int v : adj[u]) {
        if(v == f) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if(sz[v] > sz[son[u]]) son[u] = v;
    }
}

void dfs2(int u, int t) {
    top[u] = t; id[u] = ++cnt;
    if(!son[u]) return;
    dfs2(son[u], t);
    for(int v : adj[u]) {
        if(v == parent[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int main() {
    adj[1].push_back(2); adj[2].push_back(1);
    adj[1].push_back(3); adj[3].push_back(1);
    dfs1(1, 0, 1);
    dfs2(1, 1);
    return 0;
}
