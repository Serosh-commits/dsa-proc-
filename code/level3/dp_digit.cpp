#include<bits/stdc++.h>
using namespace std;

long long dp[20][2][20]; string s;
long long solve(int idx, bool tight, int sum) {
    if(idx == s.size()) return sum;
    if(dp[idx][tight][sum] != -1) return dp[idx][tight][sum];
    long long ans = 0; int limit = tight ? s[idx] - '0' : 9;
    for(int d = 0; d <= limit; d++) ans += solve(idx + 1, tight && (d == limit), sum + d);
    return dp[idx][tight][sum] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    return 0;
}
