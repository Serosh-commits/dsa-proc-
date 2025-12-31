#include <bits/stdc++.h>
using namespace std;

struct BP {
    vector<bool> bits;
    BP(const vector<vector<int>>& adj, int u = 0) {
        bits.push_back(true);
        for (int v : adj[u]) {
            BP child(adj, v);
            bits.insert(bits.end(), child.bits.begin(), child.bits.end());
        }
        bits.push_back(false);
    }
};

int main() {
    vector<vector<int>> adj = {{1, 2}, {}, {}};
    BP bp(adj);
    for (bool b : bp.bits) cout << (b ? "(" : ")");
    cout << endl;
    return 0;
}
