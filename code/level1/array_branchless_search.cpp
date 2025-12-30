#include<bits/stdc++.h>
using namespace std;

int branchlessSearch(int arr[], int n, int key) {
    int index = -1;
    for(int i = 0; i < n; i++) {
        index = (arr[i] == key) * i + (arr[i] != key) * index;
    }
    return index;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    cout << branchlessSearch(arr, 5, 3) << endl;
    return 0;
}
