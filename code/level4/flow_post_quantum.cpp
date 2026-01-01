#include <bits/stdc++.h>
using namespace std;

struct PostQuantumFlow {
    int n;
    vector<vector<int>> adj;
    PostQuantumFlow(int _n) : n(_n), adj(_n, vector<int>(_n, 0)) {}
    void addEdge(int u, int v, int cap) { adj[u][v] = cap; }
};

int main() {
    PostQuantumFlow pqf(4);
    pqf.addEdge(0, 1, 10);
    return 0;
}
