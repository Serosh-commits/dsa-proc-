#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high], i = low;
    for(int j = low; j < high; j++) if(arr[j] <= pivot) swap(arr[i++], arr[j]);
    swap(arr[i], arr[high]); return i;
}

void quicksort(vector<int>& arr, int low, int high) {
    while(low < high) {
        int pi = partition(arr, low, high);
        if(pi - low < high - pi) { quicksort(arr, low, pi - 1); low = pi + 1; }
        else { quicksort(arr, pi + 1, high); high = pi - 1; }
    }
}

int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    quicksort(arr, 0, arr.size() - 1);
    return 0;
}
