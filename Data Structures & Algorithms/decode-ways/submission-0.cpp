class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        dp[n] = 1;
        return s.empty() ? 0 : solve(0, s, dp);
    }
    int solve(int i, string& s, vector<int>& dp) {
        if(dp[i] != -1) return dp[i];
        int n = s.size();
        if (i == n)
            return dp[i] = 1;
        if (s[i] == '0')
            return dp[i] = 0;
        int res = solve(i + 1, s, dp);
        if (i < n - 1 && (s[i] == '1' || (s[i] == '2' && s[i + 1] < '7')))
            res += solve(i + 2, s, dp);
        return dp[i] = res;
    }
};