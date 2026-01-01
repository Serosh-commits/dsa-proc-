#include<bits/stdc++.h>
using namespace std;

void buildSuffixArray(string s, vector<int>& sa) {
    int n = s.length();
    vector<int> rank(n), tmp(n);
    for(int i = 0; i < n; i++) {
        sa[i] = i;
        rank[i] = s[i];
    }
    for(int k = 1; k < n; k <<= 1) {
        auto cmp = [&](int i, int j) {
            if(rank[i] != rank[j]) return rank[i] < rank[j];
            int ri = i + k < n ? rank[i + k] : -1;
            int rj = j + k < n ? rank[j + k] : -1;
            return ri < rj;
        };
        sort(sa.begin(), sa.end(), cmp);
        tmp[sa[0]] = 0;
        for(int i = 1; i < n; i++) tmp[sa[i]] = tmp[sa[i-1]] + cmp(sa[i-1], sa[i]);
        rank = tmp;
    }
}

int main() {
    string s = "banana";
    int n = s.length();
    vector<int> sa(n);
    buildSuffixArray(s, sa);
    for(int x : sa) cout << x << " ";
    return 0;
}
