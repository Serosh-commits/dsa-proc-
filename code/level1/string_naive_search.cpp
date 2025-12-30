#include<bits/stdc++.h>
using namespace std;

void naiveSearch(string txt, string pat) {
    int n = txt.length(), m = pat.length();
    for(int i = 0; i <= n - m; i++) {
        int j;
        for(j = 0; j < m; j++) if(txt[i+j] != pat[j]) break;
        if(j == m) cout << "found at " << i << endl;
    }
}

int main() {
    naiveSearch("AABAACAADAABAAABAA", "AABA");
    return 0;
}
