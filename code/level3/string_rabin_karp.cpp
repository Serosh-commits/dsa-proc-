#include<bits/stdc++.h>
using namespace std;

void rabinKarp(string txt, string pat) {
    int n = txt.size(), m = pat.size(), p = 0, t = 0, h = 1, d = 256, q = 101;
    for(int i = 0; i < m - 1; i++) h = (h * d) % q;
    for(int i = 0; i < m; i++) { p = (d * p + pat[i]) % q; t = (d * t + txt[i]) % q; }
    for(int i = 0; i <= n - m; i++) {
        if(p == t) { bool ok = true; for(int j = 0; j < m; j++) if(txt[i + j] != pat[j]) ok = false; if(ok) cout << "Found at " << i << endl; }
        if(i < n - m) { t = (d * (t - txt[i] * h) + txt[i + m]) % q; if(t < 0) t += q; }
    }
}

int main() {
    rabinKarp("GEEKS FOR GEEKS", "GEEK");
    return 0;
}
