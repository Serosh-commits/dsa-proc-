#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }

long long power(long long a, long long b, long long m) {
    long long res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (__int128)res * a % m;
        a = (__int128)a * a % m;
        b /= 2;
    }
    return res;
}

int main() {
    int n = 15;
    int a = 7;
    for (int r = 1; r < n; r++) {
        if (power(a, r, n) == 1) {
            if (r % 2 == 0) {
                long long x = power(a, r / 2, n);
                cout << "Factors: " << gcd(x - 1, n) << ", " << gcd(x + 1, n) << endl;
                break;
            }
        }
    }
    return 0;
}
