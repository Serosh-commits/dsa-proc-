#include<bits/stdc++.h>
using namespace std;

struct SuccinctBitVector {
    vector<uint64_t> bits; vector<int> rank_table;
    SuccinctBitVector(int n) { bits.resize((n + 63) / 64, 0); rank_table.resize(bits.size() + 1, 0); }
    void set(int i) { bits[i / 64] |= (1ULL << (i % 64)); }
    void build() { for(int i = 0; i < bits.size(); i++) rank_table[i+1] = rank_table[i] + __builtin_popcountll(bits[i]); }
    int rank(int i) {
        int res = rank_table[i / 64];
        res += __builtin_popcountll(bits[i / 64] & ((1ULL << (i % 64)) - 1));
        return res;
    }
};

int main() {
    SuccinctBitVector sbv(128); sbv.set(10); sbv.set(70); sbv.build();
    cout << sbv.rank(71) << endl;
    return 0;
}
