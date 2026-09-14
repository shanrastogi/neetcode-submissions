class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordDictSet;
        for (auto it : wordDict) {
            wordDictSet.insert(it);
        }
        if (checkInDict(s, wordDictSet)) {
            return true;
        }
        vector<int> dp(s.size() + 1, -1);
        return solve(0, s, wordDictSet, dp);
    }

    bool solve(int idx, string& s, unordered_set<string>& wordDictSet, vector<int>& dp) {
        if (idx == s.size()) return true;
        if (dp[idx] != -1) return dp[idx];
        for (int l = 1; l <= s.size(); l++) {
            string temp = s.substr(idx, l);
            if (checkInDict(temp, wordDictSet) && solve(idx + l, s, wordDictSet, dp))
                return dp[idx] = true;
        }
        return dp[idx] = false;
    }

    bool checkInDict(string temp, unordered_set<string>& wordDictSet) {
        return wordDictSet.find(temp) != wordDictSet.end();
    }
};
