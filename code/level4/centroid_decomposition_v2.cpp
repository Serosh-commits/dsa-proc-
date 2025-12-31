#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
int sz[MAXN]; bool vis[MAXN];

void dfs_sz(int u, int p) {
    sz[u] = 1; for(int v : adj[u]) if(v != p && !vis[v]) { dfs_sz(v, u); sz[u] += sz[v]; }
}

int find_centroid(int u, int p, int n) {
    for(int v : adj[u]) if(v != p && !vis[v] && sz[v] > n / 2) return find_centroid(v, u, n);
    return u;
}

void decompose(int u, int p) {
    dfs_sz(u, -1); int c = find_centroid(u, -1, sz[u]);
    vis[c] = true; for(int v : adj[c]) if(!vis[v]) decompose(v, c);
}

int main() {
    decompose(1, -1);
    return 0;
}
