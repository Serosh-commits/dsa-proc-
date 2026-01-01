#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], cur_pos;

int dfs_sz(int u) {
    int size = 1, max_c_size = 0;
    for(int v : adj[u]) {
        if(v != parent[u]) {
            parent[v] = u; depth[v] = depth[u] + 1;
            int c_size = dfs_sz(v); size += c_size;
            if(c_size > max_c_size) { max_c_size = c_size; heavy[u] = v; }
        }
    }
    return size;
}

void dfs_hld(int u, int h) {
    head[u] = h; pos[u] = ++cur_pos;
    if(heavy[u] != -1) dfs_hld(heavy[u], h);
    for(int v : adj[u]) if(v != parent[u] && v != heavy[u]) dfs_hld(v, v);
}

int main() {
    memset(heavy, -1, sizeof(heavy));
    dfs_sz(1); dfs_hld(1, 1);
    return 0;
}
