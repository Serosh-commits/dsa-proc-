#include <bits/stdc++.h>
using namespace std;

int main() {
    int start = 0, target = 10;
    queue<int> q;
    q.push(start);
    unordered_map<int, int> dist;
    dist[start] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == target) break;
        for (int v : {u + 1, u * 2}) {
            if (v <= target && dist.find(v) == dist.end()) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << dist[target] << endl;
    return 0;
}
