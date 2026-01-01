#include<bits/stdc++.h>
using namespace std;

struct SuccinctBitVector {
    vector<uint64_t> bits;
    vector<int> rank_table;
    int n;

    SuccinctBitVector(int _n) : n(_n) {
        bits.assign((n + 63) / 64, 0);
    }

    void set(int i) {
        bits[i / 64] |= (1ULL << (i % 64));
    }

    void build() {
        rank_table.assign(bits.size() + 1, 0);
        for(int i = 0; i < bits.size(); i++) {
            rank_table[i + 1] = rank_table[i] + __builtin_popcountll(bits[i]);
        }
    }

    int rank1(int i) {
        int idx = i / 64;
        int res = rank_table[idx];
        res += __builtin_popcountll(bits[idx] & ((1ULL << (i % 64)) - 1));
        return res;
    }

    int select1(int k) {
        int l = 0, r = n;
        int res = -1;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            if(rank1(mid) >= k) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return res;
    }
};

int main() {
    SuccinctBitVector sbv(128);
    sbv.set(10); sbv.set(20); sbv.set(30);
    sbv.build();
    cout << "Rank1(25): " << sbv.rank1(25) << endl;
    cout << "Select1(2): " << sbv.select1(2) << endl;
    return 0;
}
