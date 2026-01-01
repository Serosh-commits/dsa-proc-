#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

pair<int, vector<int>> stoer_wagner(int n, vector<vector<int>>& adj) {
    int min_cut = INF;
    vector<int> best_partition;
    vector<int> v[n];
    for(int i = 0; i < n; i++) v[i].push_back(i);

    vector<int> w(n);
    vector<bool> exist(n, true), in_a(n);

    for(int phase = 0; phase < n - 1; phase++) {
        fill(in_a.begin(), in_a.end(), false);
        fill(w.begin(), w.end(), 0);
        int prev = -1, curr = -1;
        for(int i = 0; i < n - phase; i++) {
            int next = -1;
            for(int j = 0; j < n; j++) {
                if(exist[j] && !in_a[j]) {
                    if(next == -1 || w[j] > w[next]) next = j;
                }
            }
            if(i == n - phase - 1) {
                if(w[next] < min_cut) {
                    min_cut = w[next];
                    best_partition = v[next];
                }
                for(int j = 0; j < n; j++) {
                    adj[prev][j] += adj[next][j];
                    adj[j][prev] += adj[j][next];
                }
                v[prev].insert(v[prev].end(), v[next].begin(), v[next].end());
                exist[next] = false;
            } else {
                in_a[next] = true;
                for(int j = 0; j < n; j++) {
                    if(exist[j] && !in_a[j]) w[j] += adj[next][j];
                }
                prev = curr;
                curr = next;
            }
        }
    }
    return {min_cut, best_partition};
}

int main() {
    int n = 4;
    vector<vector<int>> adj(n, vector<int>(n, 0));
    auto add_edge = [&](int u, int v, int w) {
        adj[u][v] = adj[v][u] = w;
    };
    add_edge(0, 1, 2);
    add_edge(0, 2, 3);
    add_edge(1, 2, 1);
    add_edge(1, 3, 4);
    add_edge(2, 3, 5);

    auto res = stoer_wagner(n, adj);
    cout << "Min Cut: " << res.first << endl;
    return 0;
}
