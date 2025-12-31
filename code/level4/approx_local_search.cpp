#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> path = {0, 1, 2, 3, 0};
    auto dist = [&](int u, int v) { return abs(u - v); };
    for (int i = 1; i < 4; i++) {
        for (int j = i + 1; j < 4; j++) {
            reverse(path.begin() + i, path.begin() + j + 1);
            cout << "Local search swap." << endl;
        }
    }
    return 0;
}
