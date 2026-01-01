#include<bits/stdc++.h>
using namespace std;

string getBWT(string s) {
    s += "$";
    int n = s.size();
    vector<int> sa(n);
    iota(sa.begin(), sa.end(), 0);
    sort(sa.begin(), sa.end(), [&](int a, int b) {
        return s.substr(a) < s.substr(b);
    });
    string res = "";
    for(int i = 0; i < n; i++) {
        res += s[(sa[i] + n - 1) % n];
    }
    return res;
}

int main() {
    string s = "banana";
    cout << getBWT(s) << endl;
    return 0;
}
