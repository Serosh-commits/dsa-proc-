#include<bits/stdc++.h>
using namespace std;

void partition3Way(vector<int>& arr, int low, int high) {
    if(low >= high) return;
    int lt = low, gt = high, i = low + 1, pivot = arr[low];
    while(i <= gt) {
        if(arr[i] < pivot) swap(arr[lt++], arr[i++]);
        else if(arr[i] > pivot) swap(arr[i], arr[gt--]);
        else i++;
    }
    partition3Way(arr, low, lt - 1); partition3Way(arr, gt + 1, high);
}

int main() {
    vector<int> arr = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
    partition3Way(arr, 0, arr.size() - 1);
    return 0;
}
