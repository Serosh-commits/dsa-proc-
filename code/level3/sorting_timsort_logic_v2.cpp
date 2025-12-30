#include<bits/stdc++.h>
using namespace std;

void timSortGallop(vector<int>& arr, int n) {
    int RUN = 32;
    for(int i = 0; i < n; i += RUN) {
        for(int j = i + 1; j < min(i + RUN, n); j++) {
            int temp = arr[j], k = j - 1;
            while(k >= i && arr[k] > temp) { arr[k+1] = arr[k]; k--; }
            arr[k+1] = temp;
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    timSortGallop(arr, 6);
    return 0;
}
