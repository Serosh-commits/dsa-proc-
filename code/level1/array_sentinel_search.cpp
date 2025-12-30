#include<bits/stdc++.h>
using namespace std;

int sentinelSearch(int arr[], int n, int key) {
    int last = arr[n-1];
    arr[n-1] = key;
    int i = 0;
    while(arr[i] != key) i++;
    arr[n-1] = last;
    if(i < n - 1 || arr[n-1] == key) return i;
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << sentinelSearch(arr, 5, 3) << endl;
    return 0;
}
