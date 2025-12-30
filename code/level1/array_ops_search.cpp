#include<bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int target) {
    for(int i = 0; i < n; i++) if(arr[i] == target) return i;
    return -1;
}

int sentinel_search(int arr[], int n, int target) {
    int last = arr[n-1];
    arr[n-1] = target;
    int i = 0;
    while(arr[i] != target) i++;
    arr[n-1] = last;
    if(i < n - 1 || last == target) return i;
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << linear_search(arr, 5, 3) << endl;
    cout << sentinel_search(arr, 5, 3) << endl;
    return 0;
}
