#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

int find(int i, vector<int>& parent) {
    if(parent[i] == i) return i;
    return parent[i] = find(parent[i], parent);
}

void unite(int i, int j, vector<int>& parent) {
    int root_i = find(i, parent), root_j = find(j, parent);
    if(root_i != root_j) parent[root_i] = root_j;
}

int karger(int n, vector<Edge>& edges) {
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);
    int vertices = n;
    while(vertices > 2) {
        int i = rand() % edges.size();
        int root_u = find(edges[i].u, parent), root_v = find(edges[i].v, parent);
        if(root_u != root_v) {
            unite(root_u, root_v, parent);
            vertices--;
        }
    }
    int cut_edges = 0;
    for(auto& e : edges) {
        if(find(e.u, parent) != find(e.v, parent)) cut_edges++;
    }
    return cut_edges;
}

int main() {
    srand(time(0));
    int n = 4;
    vector<Edge> edges = {{0, 1}, {0, 2}, {0, 3}, {1, 3}, {2, 3}};
    cout << karger(n, edges) << endl;
    return 0;
}
