#include<bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int v, vector<int> adj[], vector<bool>& visited, vector<bool>& recStack) {
    if(!visited[v]) {
        visited[v] = recStack[v] = true;
        for(int i : adj[v]) {
            if(!visited[i] && isCyclicUtil(i, adj, visited, recStack)) return true;
            else if(recStack[i]) return true;
        }
    }
    recStack[v] = false; return false;
}

int main() {
    int V = 4; vector<int> adj[V];
    vector<bool> visited(V, false), recStack(V, false);
    return 0;
}
