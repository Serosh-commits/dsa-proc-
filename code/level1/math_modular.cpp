#include<bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while(exp > 0) {
        if(exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

int main() {
    cout << power(2, 10, 1000000007) << endl;
    return 0;
}
