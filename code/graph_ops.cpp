#include<bits/stdc++.h>
using namespace std;

bool isCycle(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
    visited[u] = true;
    recStack[u] = true;
    for(int v : adj[u]) {
        if(!visited[v] && isCycle(v, adj, visited, recStack)) return true;
        else if(recStack[v]) return true;
    }
    recStack[u] = false;
    return false;
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n);
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[2].push_back(3);
    vector<bool> visited(n, false), recStack(n, false);
    cout << isCycle(0, adj, visited, recStack) << endl;
    return 0;
}
