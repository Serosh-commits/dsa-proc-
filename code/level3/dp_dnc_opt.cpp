#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;
long long dp[2][1005];

void compute(int l, int r, int optL, int optR, const vector<long long>& prev_dp, const vector<long long>& cost) {
    if (l > r) return;
    int mid = (l + r) / 2;
    int best_k = -1;
    dp[1][mid] = INF;
    for (int k = optL; k <= min(mid, optR); k++) {
        long long val = prev_dp[k] + (cost[mid] - cost[k]) * (mid - k);
        if (val < dp[1][mid]) {
            dp[1][mid] = val;
            best_k = k;
        }
    }
    compute(l, mid - 1, optL, best_k, prev_dp, cost);
    compute(mid + 1, r, best_k, optR, prev_dp, cost);
}

int main() {
    int n = 10, k = 3;
    vector<long long> cost(n + 1, 0);
    for (int i = 1; i <= n; i++) cost[i] = i;
    for (int i = 1; i <= n; i++) dp[0][i] = cost[i] * i;
    for (int i = 2; i <= k; i++) {
        compute(1, n, 1, n, vector<long long>(dp[0], dp[0] + n + 1), cost);
        for (int j = 1; j <= n; j++) dp[0][j] = dp[1][j];
    }
    cout << dp[0][n] << endl;
    return 0;
}
