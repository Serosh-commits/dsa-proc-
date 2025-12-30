#include<bits/stdc++.h>
using namespace std;

void partition3(vector<int>& arr, int l, int r, int& i, int& j) {
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = arr[r];
    while(true) {
        while(arr[++i] < v);
        while(v < arr[--j]) if(j == l) break;
        if(i >= j) break;
        swap(arr[i], arr[j]);
        if(arr[i] == v) { p++; swap(arr[p], arr[i]); }
        if(arr[j] == v) { q--; swap(arr[j], arr[q]); }
    }
    swap(arr[i], arr[r]);
    j = i - 1;
    for(int k = l; k < p; k++, j--) swap(arr[k], arr[j]);
    i = i + 1;
    for(int k = r - 1; k > q; k--, i++) swap(arr[i], arr[k]);
}

void quicksort3(vector<int>& arr, int l, int r) {
    if(r <= l) return;
    int i, j;
    partition3(arr, l, r, i, j);
    quicksort3(arr, l, j);
    quicksort3(arr, i, r);
}

int main() {
    vector<int> arr = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
    quicksort3(arr, 0, arr.size() - 1);
    for(int x : arr) cout << x << " ";
    return 0;
}
