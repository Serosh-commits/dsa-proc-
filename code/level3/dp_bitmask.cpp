#include<bits/stdc++.h>
using namespace std;

int n; int dist[20][20], dp[1 << 20][20];
int tsp(int mask, int pos) {
    if(mask == (1 << n) - 1) return dist[pos][0];
    if(dp[mask][pos] != -1) return dp[mask][pos];
    int ans = INT_MAX;
    for(int city = 0; city < n; city++) if(!(mask & (1 << city))) ans = min(ans, dist[pos][city] + tsp(mask | (1 << city), city));
    return dp[mask][pos] = ans;
}

int main() {
    memset(dp, -1, sizeof dp);
    return 0;
}
