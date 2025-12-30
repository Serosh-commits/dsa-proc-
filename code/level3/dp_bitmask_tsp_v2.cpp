#include<bits/stdc++.h>
using namespace std;

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
    int n = 4;
    vector<vector<int>> dist = {{0, 10, 15, 20}, {10, 0, 35, 25}, {15, 35, 0, 30}, {20, 25, 30, 0}};
    vector<vector<int>> dp(1 << n, vector<int>(n, -1));
    cout << tsp(dist, 1, 0, n, dp) << endl;
    return 0;
}
