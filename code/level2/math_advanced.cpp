#include<bits/stdc++.h>
using namespace std;

long long extendedGCD(long long a, long long b, long long &x, long long &y) {
    if(a == 0) { x = 0; y = 1; return b; }
    long long x1, y1;
    long long gcd = extendedGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return gcd;
}

long long modInverse(long long a, long long m) {
    long long x, y;
    long long g = extendedGCD(a, m, x, y);
    if(g != 1) return -1;
    return (x % m + m) % m;
}

int main() {
    cout << modInverse(3, 11) << endl;
    return 0;
}
