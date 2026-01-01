#include <bits/stdc++.h>
using namespace std;

struct EulerTourTree {
    vector<int> tour;
    void dfs(int u, int p, const vector<vector<int>>& adj) {
        tour.push_back(u);
        for (int v : adj[u]) {
            if (v != p) {
                dfs(v, u, adj);
                tour.push_back(u);
            }
        }
    }
};

int main() {
    vector<vector<int>> adj = {{1, 2}, {0}, {0}};
    EulerTourTree ett;
    ett.dfs(0, -1, adj);
    for (int x : ett.tour) cout << x << " ";
    cout << endl;
    return 0;
}
