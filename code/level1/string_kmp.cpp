#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pat, vector<int>& lps) {
    int len = 0, i = 1;
    lps[0] = 0;
    while(i < pat.length()) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) len = lps[len-1];
            else { lps[i] = 0; i++; }
        }
    }
}

void KMP(string txt, string pat) {
    int m = pat.length(), n = txt.length();
    vector<int> lps(m);
    computeLPS(pat, lps);
    int i = 0, j = 0;
    while(i < n) {
        if(pat[j] == txt[i]) { i++; j++; }
        if(j == m) {
            cout << "found at " << i - j << endl;
            j = lps[j-1];
        } else if(i < n && pat[j] != txt[i]) {
            if(j != 0) j = lps[j-1];
            else i++;
        }
    }
}

int main() {
    KMP("ababcabcabababd", "ababd");
    return 0;
}
