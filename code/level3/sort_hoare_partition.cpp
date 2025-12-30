#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[low], i = low - 1, j = high + 1;
    while(true) {
        do { i++; } while(arr[i] < pivot);
        do { j--; } while(arr[j] > pivot);
        if(i >= j) return j; swap(arr[i], arr[j]);
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    partition(arr, 0, arr.size() - 1);
    return 0;
}
