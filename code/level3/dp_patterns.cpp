#include<bits/stdc++.h>
using namespace std;

int houseRobber(vector<int>& nums) {
    int n = nums.size();
    if(n == 0) return 0;
    if(n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for(int i = 2; i < n; i++) dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
    return dp[n-1];
}

int editDistance(string s1, string s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));
    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == 0) dp[i][j] = j;
            else if(j == 0) dp[i][j] = i;
            else if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]});
        }
    }
    return dp[m][n];
}

int main() {
    vector<int> nums = {1, 2, 3, 1};
    cout << houseRobber(nums) << endl;
    cout << editDistance("sunday", "saturday") << endl;
    return 0;
}
