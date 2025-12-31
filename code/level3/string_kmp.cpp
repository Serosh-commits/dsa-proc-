#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pat, vector<int>& lps) {
    int len = 0, i = 1; lps[0] = 0;
    while(i < pat.size()) {
        if(pat[i] == pat[len]) lps[i++] = ++len;
        else { if(len != 0) len = lps[len - 1]; else lps[i++] = 0; }
    }
}

void kmp(string txt, string pat) {
    int n = txt.size(), m = pat.size(); vector<int> lps(m); computeLPS(pat, lps);
    int i = 0, j = 0;
    while(i < n) {
        if(pat[j] == txt[i]) { i++; j++; }
        if(j == m) { cout << "Found at " << i - j << endl; j = lps[j - 1]; }
        else if(i < n && pat[j] != txt[i]) { if(j != 0) j = lps[j - 1]; else i++; }
    }
}

int main() {
    kmp("ABABDABACDABABCABAB", "ABABCABAB");
    return 0;
}
