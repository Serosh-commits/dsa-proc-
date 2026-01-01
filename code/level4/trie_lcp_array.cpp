#include<bits/stdc++.h>
using namespace std;

vector<int> buildLCP(string s, vector<int>& sa) {
    int n = s.size(); vector<int> rank(n), lcp(n);
    for(int i = 0; i < n; i++) rank[sa[i]] = i;
    int k = 0;
    for(int i = 0; i < n; i++) {
        if(rank[i] == n - 1) { k = 0; continue; }
        int j = sa[rank[i] + 1];
        while(i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
        lcp[rank[i]] = k; if(k > 0) k--;
    }
    return lcp;
}

int main() {
    return 0;
}
