#include<bits/stdc++.h>
using namespace std;

string preProcess(string s) {
    int n = s.length();
    if(n == 0) return "^$";
    string res = "^";
    for(int i = 0; i < n; i++) res += "#" + s.substr(i, 1);
    res += "#$";
    return res;
}

int main() {
    string s = "aba";
    string T = preProcess(s);
    int n = T.length();
    vector<int> P(n, 0);
    int C = 0, R = 0;
    for(int i = 1; i < n - 1; i++) {
        int i_mirror = 2 * C - i;
        if(R > i) P[i] = min(R - i, P[i_mirror]);
        while(T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;
        if(i + P[i] > R) { C = i; R = i + P[i]; }
    }
    return 0;
}
