#include <bits/stdc++.h>
using namespace std;

struct CSR {
    vector<int> row_ptr, col_idx;
    CSR(int V, const vector<pair<int, int>>& edges) {
        row_ptr.assign(V + 1, 0);
        for (auto& e : edges) row_ptr[e.first + 1]++;
        for (int i = 0; i < V; i++) row_ptr[i + 1] += row_ptr[i];
        col_idx.resize(edges.size());
        vector<int> curr = row_ptr;
        for (auto& e : edges) col_idx[curr[e.first]++] = e.second;
    }
};

int main() {
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {1, 2}, {2, 3}};
    CSR g(4, edges);
    for (int i = 0; i < 4; i++) {
        cout << i << ": ";
        for (int j = g.row_ptr[i]; j < g.row_ptr[i + 1]; j++) cout << g.col_idx[j] << " ";
        cout << endl;
    }
    return 0;
}
