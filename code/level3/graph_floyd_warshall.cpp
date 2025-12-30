#include<bits/stdc++.h>
using namespace std;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for(int k = 0; k < V; k++) for(int i = 0; i < V; i++) for(int j = 0; j < V; j++) if(dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main() {
    int V = 4; vector<vector<int>> dist(V, vector<int>(V, INT_MAX));
    for(int i = 0; i < V; i++) dist[i][i] = 0;
    floydWarshall(dist, V);
    return 0;
}
