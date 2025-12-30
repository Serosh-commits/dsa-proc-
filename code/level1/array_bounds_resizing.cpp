#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 5;
    int* arr = new int[n];
    for(int i = 0; i < n; i++) arr[i] = i;

    int new_n = 10;
    int* new_arr = new int[new_n];
    for(int i = 0; i < n; i++) new_arr[i] = arr[i];
    delete[] arr;
    arr = new_arr;

    for(int i = 0; i < new_n; i++) cout << arr[i] << " ";
    cout << endl;
    return 0;
}
