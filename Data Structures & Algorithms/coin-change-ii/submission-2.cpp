class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
        for (int i = 0; i <= amount; i++) {
            dp[0][i] = (i % coins[0] == 0);
        }
        for (int i = 1; i < n; i++) {
            for (int t = 0; t <= amount; t++) {
                int take = 0;
                if (coins[i] <= t) take = dp[i][t - coins[i]];
                int notake = dp[i - 1][t];
                dp[i][t] = take + notake;
            }
        }
        return dp[n - 1][amount];
    }
};
