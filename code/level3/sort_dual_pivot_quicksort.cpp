#include<bits/stdc++.h>
using namespace std;

void dualPivotQuicksort(vector<int>& arr, int low, int high) {
    if(low < high) {
        if(arr[low] > arr[high]) swap(arr[low], arr[high]);
        int p = arr[low], q = arr[high], i = low + 1, j = high - 1, k = low + 1;
        while(k <= j) {
            if(arr[k] < p) swap(arr[k], arr[i++]);
            else if(arr[k] >= q) { while(arr[j] > q && k < j) j--; swap(arr[k], arr[j--]); if(arr[k] < p) swap(arr[k], arr[i++]); }
            k++;
        }
        i--; j++; swap(arr[low], arr[i]); swap(arr[high], arr[j]);
        dualPivotQuicksort(arr, low, i - 1); dualPivotQuicksort(arr, i + 1, j - 1); dualPivotQuicksort(arr, j + 1, high);
    }
}

int main() {
    vector<int> arr = {24, 8, 42, 75, 29, 77, 38, 57};
    dualPivotQuicksort(arr, 0, arr.size() - 1);
    return 0;
}
