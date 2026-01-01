#include <bits/stdc++.h>
using namespace std;

struct ZKP {
    long long secret;
    long long p = 1000000007;
    long long g = 5;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= p;
        while (exp > 0) {
            if (exp % 2 == 1) res = (__int128)res * base % p;
            base = (__int128)base * base % p;
            exp /= 2;
        }
        return res;
    }

    pair<long long, long long> commit() {
        long long r = rand() % (p - 1);
        return {r, power(g, r)};
    }

    bool verify(long long y, long long r, long long commitment, int challenge) {
        if (challenge == 0) return power(g, r) == commitment;
        return power(g, r) == (commitment * power(y, 1)) % p; 
    }
};

int main() {
    ZKP zkp;
    zkp.secret = 123456;
    long long y = zkp.power(zkp.g, zkp.secret);
    auto comm = zkp.commit();
    cout << "ZKP Verification: " << zkp.verify(y, comm.first, comm.second, 0) << endl;
    return 0;
}
