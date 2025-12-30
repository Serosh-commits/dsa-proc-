#include<bits/stdc++.h>
using namespace std;

void partition(int arr[], int l, int r, int &i, int &j) {
    if(r - l <= 1) { if(arr[r] < arr[l]) swap(arr[r], arr[l]); i = l; j = r; return; }
    int mid = l, pivot = arr[r];
    while(mid <= r) {
        if(arr[mid] < pivot) swap(arr[l++], arr[mid++]);
        else if(arr[mid] == pivot) mid++;
        else swap(arr[mid], arr[r--]);
    }
    i = l - 1; j = mid;
}

void quicksort(int arr[], int l, int r) {
    if(l >= r) return;
    int i, j;
    partition(arr, l, r, i, j);
    quicksort(arr, l, i); quicksort(arr, j, r);
}

int main() {
    int arr[] = {4, 9, 4, 4, 1, 9, 4, 4, 9, 4, 4, 1, 4};
    quicksort(arr, 0, 12);
    return 0;
}
