#include<bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N]; int parent[N], depth[N], heavy[N], head[N], pos[N], cur_pos;

int dfs_sz(int u) {
    int size = 1, max_child_size = 0;
    for(int v : adj[u]) {
        if(v != parent[u]) {
            parent[v] = u; depth[v] = depth[u] + 1;
            int child_size = dfs_sz(v); size += child_size;
            if(child_size > max_child_size) { max_child_size = child_size; heavy[u] = v; }
        }
    }
    return size;
}

void decompose(int u, int h) {
    head[u] = h; pos[u] = ++cur_pos;
    if(heavy[u] != -1) decompose(heavy[u], h);
    for(int v : adj[u]) if(v != parent[u] && v != heavy[u]) decompose(v, v);
}

int main() {
    memset(heavy, -1, sizeof heavy);
    return 0;
}
