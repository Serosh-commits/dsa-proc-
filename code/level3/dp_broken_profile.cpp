#include <bits/stdc++.h>
using namespace std;

long long dp[2][1 << 10];

int main() {
    int n = 4, m = 4;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            memset(dp[1], 0, sizeof(dp[1]));
            for (int mask = 0; mask < (1 << m); mask++) {
                if (dp[0][mask]) {
                    if (mask & (1 << j)) dp[1][mask ^ (1 << j)] += dp[0][mask];
                    else {
                        dp[1][mask ^ (1 << j)] += dp[0][mask];
                        if (j + 1 < m && !(mask & (1 << (j + 1)))) dp[1][mask ^ (1 << (j + 1))] += dp[0][mask];
                    }
                }
            }
            memcpy(dp[0], dp[1], sizeof(dp[0]));
        }
    }
    cout << dp[0][0] << endl;
    return 0;
}
