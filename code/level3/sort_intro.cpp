#include <bits/stdc++.h>
using namespace std;

void introSort(vector<int>& arr, int n) {
    make_heap(arr.begin(), arr.end());
    sort_heap(arr.begin(), arr.end());
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    introSort(arr, arr.size());
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
