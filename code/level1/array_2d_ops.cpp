#include<bits/stdc++.h>
using namespace std;

int main() {
    int r, c;
    cin >> r >> c;
    int mat[r][c];
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            mat[i][j] = i * c + j;
        }
    }
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
