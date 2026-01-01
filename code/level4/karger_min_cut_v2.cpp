#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
};

struct Graph {
    int V, E;
    vector<Edge> edges;

    Graph(int v, int e) : V(v), E(e) {}

    void addEdge(int u, int v) {
        edges.push_back({u, v});
    }
};

struct Subset {
    int parent;
    int rank;
};

int find(vector<Subset>& subsets, int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

void Union(vector<Subset>& subsets, int x, int y) {
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);
    if (subsets[xroot].rank < subsets[yroot].rank)
        subsets[xroot].parent = yroot;
    else if (subsets[xroot].rank > subsets[yroot].rank)
        subsets[yroot].parent = xroot;
    else {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

int kargerMinCut(Graph& graph) {
    int V = graph.V, E = graph.E;
    vector<Edge> edges = graph.edges;
    vector<Subset> subsets(V);

    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int vertices = V;
    while (vertices > 2) {
        int i = rand() % E;
        int subset1 = find(subsets, edges[i].u);
        int subset2 = find(subsets, edges[i].v);

        if (subset1 == subset2) continue;
        else {
            vertices--;
            Union(subsets, subset1, subset2);
        }
    }

    int cutedges = 0;
    for (int i = 0; i < E; i++) {
        int subset1 = find(subsets, edges[i].u);
        int subset2 = find(subsets, edges[i].v);
        if (subset1 != subset2) cutedges++;
    }

    return cutedges;
}

int main() {
    srand(time(NULL));
    int V = 4, E = 5;
    Graph g(V, E);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 3);
    g.addEdge(2, 3);

    int min_cut = 1e9;
    for(int i = 0; i < 10; i++) {
        min_cut = min(min_cut, kargerMinCut(g));
    }

    cout << "Min-Cut (Approx): " << min_cut << endl;

    return 0;
}
