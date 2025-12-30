#include <bits/stdc++.h>
using namespace std;

void compareSwap(int& a, int& b) {
    if (a > b) swap(a, b);
}

void bitonicSort(vector<int>& a, int low, int cnt, bool dir) {
    if (cnt > 1) {
        int k = cnt / 2;
        for (int i = low; i < low + k; i++) compareSwap(a[i], a[i + k]);
        bitonicSort(a, low, k, dir);
        bitonicSort(a, low + k, k, dir);
    }
}

int main() {
    vector<int> a = {3, 7, 4, 8, 6, 2, 1, 5};
    bitonicSort(a, 0, 8, true);
    for (int x : a) cout << x << " ";
    cout << endl;
    return 0;
}
