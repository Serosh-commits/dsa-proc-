#include<bits/stdc++.h>
using namespace std;

int linearSearch(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) if(arr[i] == key) return i;
    return -1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << linearSearch(arr, 5, 3) << endl;
    return 0;
}
