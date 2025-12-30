#include<bits/stdc++.h>
using namespace std;

int lomutoPartition(vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l - 1;
    for(int j = l; j < r; j++) {
        if(arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i + 1;
}

int hoarePartition(vector<int>& arr, int l, int r) {
    int pivot = arr[l], i = l - 1, j = r + 1;
    while(true) {
        do { i++; } while(arr[i] < pivot);
        do { j--; } while(arr[j] > pivot);
        if(i >= j) return j;
        swap(arr[i], arr[j]);
    }
}

int quickSelect(vector<int>& arr, int l, int r, int k) {
    if(k > 0 && k <= r - l + 1) {
        int index = lomutoPartition(arr, l, r);
        if(index - l == k - 1) return arr[index];
        if(index - l > k - 1) return quickSelect(arr, l, index - 1, k);
        return quickSelect(arr, index + 1, r, k - index + l - 1);
    }
    return INT_MAX;
}

int main() {
    vector<int> arr = {10, 4, 5, 8, 6, 11, 26};
    cout << quickSelect(arr, 0, 6, 3) << endl;
    return 0;
}
