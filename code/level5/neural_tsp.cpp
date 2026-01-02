#include <bits/stdc++.h>
using namespace std;

int main() {
    int n = 4;
    vector<int> path = {0, 1, 2, 3};
    for (int iter = 0; iter < 100; iter++) {
        int i = rand() % n, j = rand() % n;
        swap(path[i], path[j]);
    }
    for (int x : path) cout << x << " ";
    cout << endl;
    return 0;
}
