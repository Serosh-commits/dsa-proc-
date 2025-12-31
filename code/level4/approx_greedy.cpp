#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 5, k = 2;
    vector<set<int>> sets = {{0, 1, 2}, {2, 3}, {3, 4}, {0, 4}, {1, 3}};
    set<int> uncovered;
    for (int i = 0; i < n; i++) uncovered.insert(i);
    vector<int> selected;
    while (!uncovered.empty()) {
        int best = -1, max_cover = 0;
        for (int i = 0; i < sets.size(); i++) {
            int cover = 0;
            for (int x : sets[i]) if (uncovered.count(x)) cover++;
            if (cover > max_cover) { max_cover = cover; best = i; }
        }
        if (best == -1) break;
        selected.push_back(best);
        for (int x : sets[best]) uncovered.erase(x);
    }
    for (int x : selected) cout << x << " ";
    cout << endl;
    return 0;
}
