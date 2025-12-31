#include<bits/stdc++.h>
using namespace std;

struct FenwickTree {
    vector<int> bit; int n;
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}
    void update(int i, int delta) { for(; i <= n; i += i & -i) bit[i] += delta; }
    int query(int i) { int res = 0; for(; i > 0; i -= i & -i) res += bit[i]; return res; }
};

int main() {
    FenwickTree ft(10); ft.update(1, 5);
    return 0;
}
