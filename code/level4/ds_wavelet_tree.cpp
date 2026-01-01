#include<bits/stdc++.h>
using namespace std;

struct WaveletTree {
    int lo, hi;
    WaveletTree *l, *r;
    vector<int> b;

    WaveletTree(int *from, int *to, int x, int y) {
        lo = x, hi = y;
        if(lo == hi || from >= to) { l = r = NULL; return; }
        int mid = lo + (hi - lo) / 2;
        auto f = [mid](int x) { return x <= mid; };
        b.reserve(to - from + 1);
        b.push_back(0);
        for(auto it = from; it != to; it++) b.push_back(b.back() + f(*it));
        auto pivot = stable_partition(from, to, f);
        l = new WaveletTree(from, pivot, lo, mid);
        r = new WaveletTree(pivot, to, mid + 1, hi);
    }

    int kth(int i, int j, int k) {
        if(i > j) return 0;
        if(lo == hi) return lo;
        int inLeft = b[j] - b[i - 1];
        if(k <= inLeft) return l->kth(b[i - 1] + 1, b[j], k);
        return r->kth(i - b[i - 1], j - b[j], k - inLeft);
    }

    int count(int i, int j, int k) {
        if(i > j || k < lo || k > hi) return 0;
        if(lo == hi) return j - i + 1;
        int mid = lo + (hi - lo) / 2;
        if(k <= mid) return l->count(b[i - 1] + 1, b[j], k);
        return r->count(i - b[i - 1], j - b[j], k);
    }
};

int main() {
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6, 5};
    int n = sizeof(a) / sizeof(a[0]);
    WaveletTree wt(a, a + n, 1, 10);
    cout << "3rd smallest in range [2, 6]: " << wt.kth(2, 6, 3) << endl;
    return 0;
}
