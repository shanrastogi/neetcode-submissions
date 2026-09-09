class Solution {
   public:
    int solve(string& s, int i, int j, vector<vector<int>>& dp) {
        if (i >= j) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == s[j]) {
            return dp[i][j] = solve(s, i + 1, j - 1, dp);
        }

        return dp[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;

        vector<vector<int>> dp(n, vector<int>(n, -1));
        int maxLen = 0;
        int start = 0;

        for (int len = n; len >= 1; len--) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;

                if (solve(s, i, j, dp)) {
                    return s.substr(i, len);
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
