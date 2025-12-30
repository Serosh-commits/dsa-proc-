#include<bits/stdc++.h>
using namespace std;

void sieve(int n) {
    vector<bool> prime(n + 1, true);
    for(int p = 2; p * p <= n; p++) if(prime[p]) for(int i = p * p; i <= n; i += p) prime[i] = false;
}

int main() {
    sieve(100);
    return 0;
}
