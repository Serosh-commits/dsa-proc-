#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {5, 2, 9, 1, 5, 6};
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size() - 1; j++) {
            double weight = (double)rand() / RAND_MAX;
            if (weight > 0.5 && a[j] > a[j + 1]) swap(a[j], a[j + 1]);
        }
    }
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
