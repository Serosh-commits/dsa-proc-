#include <bits/stdc++.h>
using namespace std;

struct IsogenyDS {
    long long p = 431;
    long long j_invariant;
    IsogenyDS(long long j) : j_invariant(j) {}
    long long computeNext(long long l) {
        return (j_invariant * l) % p;
    }
};

int main() {
    IsogenyDS ds(1728);
    cout << "Next j-invariant: " << ds.computeNext(3) << endl;
    return 0;
}
