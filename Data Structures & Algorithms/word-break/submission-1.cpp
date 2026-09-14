class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if (checkInDict(s, wordDict)) {
            return true;
        }
        vector<int> dp(s.size() + 1, -1);
        return solve(0, s, wordDict, dp);
    }

    bool solve(int idx, string& s, vector<string>& wordDict, vector<int>& dp) {
        if (idx == s.size()) return true;
        if (dp[idx] != -1) return dp[idx];
        for (int l = 1; l <= s.size(); l++) {
            string temp = s.substr(idx, l);
            if (checkInDict(temp, wordDict) && solve(idx + l, s, wordDict, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }

    bool checkInDict(string temp, vector<string>& wordDict) {
        for (auto it : wordDict)
            if (temp == it) return true;
        return false;
    }
};
