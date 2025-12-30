#include<bits/stdc++.h>
using namespace std;

int main() {
    int fixed_arr[10];
    int n;
    cin >> n;
    int* dynamic_arr = (int*)malloc(n * sizeof(int));
    dynamic_arr = (int*)realloc(dynamic_arr, (n + 5) * sizeof(int));
    free(dynamic_arr);
    return 0;
}
