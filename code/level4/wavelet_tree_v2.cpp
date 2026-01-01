#include<bits/stdc++.h>
using namespace std;

struct WaveletTree {
    int lo, hi; WaveletTree *l, *r; vector<int> b;
    WaveletTree(int *from, int *to, int x, int y) {
        lo = x, hi = y; if(lo == hi || from >= to) return;
        int mid = (lo + hi) / 2; auto f = [mid](int x) { return x <= mid; };
        b.reserve(to - from + 1); b.push_back(0);
        for(auto it = from; it != to; it++) b.push_back(b.back() + f(*it));
        auto pivot = stable_partition(from, to, f);
        l = new WaveletTree(from, pivot, lo, mid); r = new WaveletTree(pivot, to, mid + 1, hi);
    }
};

int main() {
    int a[] = {2, 1, 3, 5, 4}; WaveletTree wt(a, a + 5, 1, 5);
    return 0;
}
