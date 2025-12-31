#include<bits/stdc++.h>
using namespace std;

struct Query { int l, r, id; };
int main() {
    int n = 10, q = 5, blockSize = sqrt(n); vector<Query> queries(q);
    sort(queries.begin(), queries.end(), [&](Query a, Query b) {
        if(a.l / blockSize != b.l / blockSize) return a.l < b.l;
        return (a.l / blockSize) % 2 ? a.r < b.r : a.r > b.r;
    });
    return 0;
}
