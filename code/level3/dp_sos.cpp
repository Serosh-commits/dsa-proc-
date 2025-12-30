#include<bits/stdc++.h>
using namespace std;

int main() {
    int N = 20; vector<int> F(1 << N);
    for(int i = 0; i < N; ++i) for(int mask = 0; mask < (1 << N); ++mask) if(mask & (1 << i)) F[mask] += F[mask ^ (1 << i)];
    return 0;
}
