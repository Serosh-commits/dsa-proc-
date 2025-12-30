#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;
}

bool isPrime(int n) {
    if(n < 2) return false;
    for(int i = 2; i * i <= n; i++) if(n % i == 0) return false;
    return true;
}

int main() {
    cout << gcd(12, 18) << endl;
    cout << lcm(12, 18) << endl;
    cout << isPrime(17) << endl;
    return 0;
}
