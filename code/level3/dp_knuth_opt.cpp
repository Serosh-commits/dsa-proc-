#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int solve(vector<int>& a) {
    int n = a.size();
    vector<vector<int>> dp(n, vector<int>(n, INF));
    vector<vector<int>> opt(n, vector<int>(n));
    for (int i = 0; i < n - 1; i++) {
        dp[i][i + 1] = 0;
        opt[i][i + 1] = i;
    }
    for (int len = 2; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; k++) {
                int val = dp[i][k] + dp[k][j] + a[j] - a[i];
                if (val < dp[i][j]) {
                    dp[i][j] = val;
                    opt[i][j] = k;
                }
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> a = {0, 2, 4, 7, 10};
    cout << solve(a) << endl;
    return 0;
}
