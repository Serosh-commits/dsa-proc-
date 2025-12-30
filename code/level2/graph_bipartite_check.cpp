#include<bits/stdc++.h>
using namespace std;

bool isBipartite(int V, vector<int> adj[]) {
    vector<int> color(V, -1);
    for(int i = 0; i < V; i++) {
        if(color[i] == -1) {
            queue<pair<int, int>> q; q.push({i, 0}); color[i] = 0;
            while(!q.empty()) {
                pair<int, int> p = q.front(); q.pop();
                int v = p.first, c = p.second;
                for(int j : adj[v]) {
                    if(color[j] == c) return false;
                    if(color[j] == -1) { color[j] = 1 - c; q.push({j, color[j]}); }
                }
            }
        }
    }
    return true;
}

int main() {
    int V = 4; vector<int> adj[V];
    cout << isBipartite(V, adj) << endl;
    return 0;
}
