#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int DIM = 16;

struct Node {
    vector<float> features;
    vector<int> adj;
    Node() { features.assign(DIM, 0.0f); }
};

void messagePassing(vector<Node>& graph) {
    int n = graph.size();
    vector<vector<float>> next_features(n, vector<float>(DIM, 0.0f));
    for(int i = 0; i < n; i++) {
        for(int neighbor : graph[i].adj) {
            for(int d = 0; d < DIM; d++) {
                next_features[i][d] += graph[neighbor].features[d];
            }
        }
        for(int d = 0; d < DIM; d++) {
            next_features[i][d] = tanh(next_features[i][d] / (graph[i].adj.size() + 1));
        }
    }
    for(int i = 0; i < n; i++) graph[i].features = next_features[i];
}

int main() {
    srand(time(0));
    int n = 5;
    vector<Node> graph(n);
    for(int i = 0; i < n; i++) {
        for(int d = 0; d < DIM; d++) graph[i].features[d] = (float)rand() / RAND_MAX;
        graph[i].adj.push_back((i + 1) % n);
        graph[(i + 1) % n].adj.push_back(i);
    }
    for(int iter = 0; iter < 5; iter++) messagePassing(graph);
    for(int d = 0; d < DIM; d++) cout << graph[0].features[d] << " ";
    cout << endl;
    return 0;
}
