#include <bits/stdc++.h>
using namespace std;

long long dp[20][2][20];
vector<int> num;

long long solve(int idx, bool tight, int count) {
    if (idx == num.size()) return count;
    if (dp[idx][tight][count] != -1) return dp[idx][tight][count];
    long long res = 0;
    int limit = tight ? num[idx] : 9;
    for (int d = 0; d <= limit; d++) {
        res += solve(idx + 1, tight && (d == limit), count + (d == 1));
    }
    return dp[idx][tight][count] = res;
}

long long countOnes(long long n) {
    num.clear();
    while (n > 0) { num.push_back(n % 10); n /= 10; }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return solve(0, true, 0);
}

int main() {
    cout << countOnes(100) << endl;
    return 0;
}
