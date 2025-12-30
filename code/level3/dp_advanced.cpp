#include<bits/stdc++.h>
using namespace std;

int matrixChain(vector<int>& p, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int len = 2; len < n; len++) {
        for(int i = 1; i < n - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k <= j - 1; k++) {
                int q = dp[i][k] + dp[k+1][j] + p[i-1] * p[k] * p[j];
                if(q < dp[i][j]) dp[i][j] = q;
            }
        }
    }
    return dp[1][n-1];
}

int tsp(vector<vector<int>>& dist, int mask, int pos, int n, vector<vector<int>>& dp) {
    if(mask == (1 << n) - 1) return dist[pos][0];
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INT_MAX;
    for(int city = 0; city < n; city++) {
        if((mask & (1 << city)) == 0) {
            int newAns = dist[pos][city] + tsp(dist, mask | (1 << city), city, n, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    vector<int> p = {10, 20, 30, 40, 30};
    cout << matrixChain(p, 5) << endl;
    int n = 4;
    vector<vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    cout << tsp(dist, 1, 0, n, dp) << endl;
    return 0;
}
