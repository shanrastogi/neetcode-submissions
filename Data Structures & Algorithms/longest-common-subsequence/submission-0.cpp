class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(m - 1, n - 1, m, n, text1, text2, dp);
    }
    int solve(int i, int j, int m, int n, string text1, string text2, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i - 1, j - 1, m, n, text1, text2, dp);
        }
        return dp[i][j] = max(solve(i - 1, j, m, n, text1, text2, dp),
                              solve(i, j - 1, m, n, text1, text2, dp));
    }
};
