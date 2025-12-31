#include <bits/stdc++.h>
using namespace std;

struct LOUDS {
    vector<bool> bits;
    vector<int> rank1;

    LOUDS(const vector<vector<int>>& adj) {
        bits.push_back(true); bits.push_back(false);
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                bits.push_back(true);
                q.push(v);
            }
            bits.push_back(false);
        }
        rank1.assign(bits.size() + 1, 0);
        for (int i = 0; i < bits.size(); i++) rank1[i + 1] = rank1[i] + bits[i];
    }
};

int main() {
    vector<vector<int>> adj = {{1, 2}, {}, {}};
    LOUDS louds(adj);
    for (bool b : louds.bits) cout << b;
    cout << endl;
    return 0;
}
