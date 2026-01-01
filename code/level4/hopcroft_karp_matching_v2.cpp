#include <bits/stdc++.h>
using namespace std;

struct HopcroftKarp {
    int n, m;
    vector<vector<int>> adj;
    vector<int> pairU, pairV, dist;

    HopcroftKarp(int _n, int _m) : n(_n), m(_m), adj(_n + 1), pairU(_n + 1, 0), pairV(_m + 1, 0), dist(_n + 1) {}

    void addEdge(int u, int v) { adj[u].push_back(v); }

    bool bfs() {
        queue<int> q;
        for (int u = 1; u <= n; u++) {
            if (pairU[u] == 0) { dist[u] = 0; q.push(u); }
            else dist[u] = 1e9;
        }
        dist[0] = 1e9;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (dist[u] < dist[0]) {
                for (int v : adj[u]) {
                    if (dist[pairV[v]] == 1e9) {
                        dist[pairV[v]] = dist[u] + 1;
                        q.push(pairV[v]);
                    }
                }
            }
        }
        return dist[0] != 1e9;
    }

    bool dfs(int u) {
        if (u != 0) {
            for (int v : adj[u]) {
                if (dist[pairV[v]] == dist[u] + 1) {
                    if (dfs(pairV[v])) {
                        pairV[v] = u;
                        pairU[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = 1e9;
            return false;
        }
        return true;
    }

    int maxMatching() {
        int matching = 0;
        while (bfs()) {
            for (int u = 1; u <= n; u++) if (pairU[u] == 0 && dfs(u)) matching++;
        }
        return matching;
    }
};

int main() {
    HopcroftKarp hk(4, 4);
    hk.addEdge(1, 2); hk.addEdge(1, 3); hk.addEdge(2, 1); hk.addEdge(3, 2); hk.addEdge(4, 2); hk.addEdge(4, 4);
    cout << hk.maxMatching() << endl;
    return 0;
}
