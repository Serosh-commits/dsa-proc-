#include<bits/stdc++.h>
using namespace std;

long long power(long long x, long long y, long long p) {
    long long res = 1; x %= p;
    while(y > 0) {
        if(y & 1) res = (res * x) % p;
        y = y >> 1; x = (x * x) % p;
    }
    return res;
}

int main() {
    cout << power(2, 10, 1000000007) << endl;
    return 0;
}
