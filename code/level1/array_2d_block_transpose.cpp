#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 4, block = 2;
    int arr[4][4], trans[4][4];
    for(int i = 0; i < n; i += block) {
        for(int j = 0; j < n; j += block) {
            for(int ii = i; ii < i + block; ii++) {
                for(int jj = j; jj < j + block; jj++) {
                    trans[jj][ii] = arr[ii][jj];
                }
            }
        }
    }
    return 0;
}
