#include<bits/stdc++.h>
using namespace std;

vector<int> manacher(string s) {
    string t = "#"; for(char c : s) { t += c; t += "#"; }
    int n = t.size(); vector<int> p(n, 0); int c = 0, r = 0;
    for(int i = 0; i < n; i++) {
        int mirr = 2 * c - i;
        if(i < r) p[i] = min(r - i, p[mirr]);
        while(i + 1 + p[i] < n && i - 1 - p[i] >= 0 && t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
        if(i + p[i] > r) { c = i; r = i + p[i]; }
    }
    return p;
}

int main() {
    manacher("abaaba");
    return 0;
}
