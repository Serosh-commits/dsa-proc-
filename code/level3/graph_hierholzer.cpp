#include<bits/stdc++.h>
using namespace std;

void hierholzer(int V, vector<int> adj[]) {
    stack<int> curr_path; vector<int> circuit; curr_path.push(0);
    while(!curr_path.empty()) {
        int u = curr_path.top();
        if(!adj[u].empty()) { int v = adj[u].back(); adj[u].pop_back(); curr_path.push(v); }
        else { circuit.push_back(u); curr_path.pop(); }
    }
}

int main() {
    int V = 5; vector<int> adj[V];
    hierholzer(V, adj);
    return 0;
}
