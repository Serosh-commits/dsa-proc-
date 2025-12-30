#include <bits/stdc++.h>
using namespace std;

struct Modular {
    long long mod;
    Modular(long long m) : mod(m) {}

    long long add(long long a, long long b) { return (a + b) % mod; }
    long long sub(long long a, long long b) { return (a - b + mod) % mod; }
    long long mul(long long a, long long b) { return (a * b) % mod; }

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }

    long long inv(long long n) {
        return power(n, mod - 2); 
    }
};

int main() {
    Modular m(1e9 + 7);
    long long a = 123456789, b = 987654321;
    cout << "Add: " << m.add(a, b) << endl;
    cout << "Sub: " << m.sub(a, b) << endl;
    cout << "Mul: " << m.mul(a, b) << endl;
    cout << "Inv: " << m.inv(a) << endl;
    return 0;
}
