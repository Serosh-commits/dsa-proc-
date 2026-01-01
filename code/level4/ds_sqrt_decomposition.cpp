#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 100, b = sqrt(n); vector<int> a(n), blocks(b + 1);
    for(int i = 0; i < n; i++) blocks[i / b] += a[i];
    return 0;
}
