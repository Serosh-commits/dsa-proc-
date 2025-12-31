#include<bits/stdc++.h>
using namespace std;

vector<int> zAlgo(string s) {
    int n = s.length(); vector<int> z(n); int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i <= r) z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if(i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

int main() {
    string s = "baabaa"; vector<int> z = zAlgo(s);
    for(int x : z) cout << x << " ";
    return 0;
}
