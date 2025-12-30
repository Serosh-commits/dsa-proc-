#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100005]; int dp[100005][2];
void dfs(int u, int p) {
    dp[u][0] = 0; dp[u][1] = 1;
    for(int v : adj[u]) {
        if(v == p) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}

int main() {
    return 0;
}
