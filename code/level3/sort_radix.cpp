#include<bits/stdc++.h>
using namespace std;

void radixSort(vector<int>& arr) {
    int m = *max_element(arr.begin(), arr.end());
    for(int exp = 1; m / exp > 0; exp *= 10) {
        vector<int> output(arr.size()), count(10, 0);
        for(int x : arr) count[(x / exp) % 10]++;
        for(int i = 1; i < 10; i++) count[i] += count[i - 1];
        for(int i = arr.size() - 1; i >= 0; i--) { output[count[(arr[i] / exp) % 10] - 1] = arr[i]; count[(arr[i] / exp) % 10]--; }
        arr = output;
    }
}

int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    radixSort(arr);
    return 0;
}
