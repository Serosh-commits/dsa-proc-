#include<bits/stdc++.h>
using namespace std;

long long computeHash(string const& s) {
    const int p = 31, m = 1e9 + 9;
    long long hash_value = 0, p_pow = 1;
    for(char c : s) { hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m; p_pow = (p_pow * p) % m; }
    return hash_value;
}

int main() {
    cout << computeHash("hello") << endl;
    return 0;
}
