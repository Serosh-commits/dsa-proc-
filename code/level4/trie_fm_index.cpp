#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "banana$";
    int n = s.length();
    vector<int> sa(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int a, int b) { return s.substr(a) < s.substr(b); });
    string bwt = "";
    for (int i = 0; i < n; i++) bwt += s[(sa[i] + n - 1) % n];
    cout << bwt << endl;
    return 0;
}
