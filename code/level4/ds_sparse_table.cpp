#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 10; vector<int> a(n); vector<vector<int>> st(n, vector<int>(20));
    for(int i = 0; i < n; i++) st[i][0] = a[i];
    for(int j = 1; j < 20; j++) for(int i = 0; i + (1 << j) <= n; i++) st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    return 0;
}
