#include <bits/stdc++.h>
using namespace std;

void dualPivotQuicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int lp, rp;
        int p1 = arr[low], p2 = arr[high];
        if (p1 > p2) { swap(arr[low], arr[high]); p1 = arr[low]; p2 = arr[high]; }
        int j = low + 1, g = high - 1, k = low + 1;
        while (k <= g) {
            if (arr[k] < p1) { swap(arr[k], arr[j]); j++; }
            else if (arr[k] >= p2) {
                while (arr[g] > p2 && k < g) g--;
                swap(arr[k], arr[g]); g--;
                if (arr[k] < p1) { swap(arr[k], arr[j]); j++; }
            }
            k++;
        }
        j--; g++;
        swap(arr[low], arr[j]); swap(arr[high], arr[g]);
        lp = j; rp = g;
        dualPivotQuicksort(arr, low, lp - 1);
        dualPivotQuicksort(arr, lp + 1, rp - 1);
        dualPivotQuicksort(arr, rp + 1, high);
    }
}

int main() {
    vector<int> arr = {24, 8, 42, 75, 29, 77, 38, 57};
    dualPivotQuicksort(arr, 0, arr.size() - 1);
    for (int x : arr) cout << x << " ";
    cout << endl;
    return 0;
}
