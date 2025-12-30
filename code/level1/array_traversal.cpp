#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
    for(int i = n - 1; i >= 0; i--) cout << arr[i] << " ";
    return 0;
}
