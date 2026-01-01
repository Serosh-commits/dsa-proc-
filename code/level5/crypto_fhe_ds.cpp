#include <bits/stdc++.h>
using namespace std;

struct FHE_Int {
    long long value;
    long long noise;
    static const long long Q = 1000000007;
    static const long long P = 10007;

    FHE_Int(long long v = 0) {
        noise = (rand() % 10) + 1;
        value = v + noise * P;
    }

    FHE_Int operator+(const FHE_Int& other) const {
        FHE_Int res;
        res.value = (value + other.value) % Q;
        return res;
    }

    long long decrypt() const {
        return value % P;
    }
};

int main() {
    FHE_Int a(5), b(10);
    FHE_Int c = a + b;

    cout << "Enc(5) + Enc(10) = Enc(" << c.decrypt() << ")" << endl;
    return 0;
}
