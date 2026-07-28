class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;
        int i = 0;
        int j = 0;
        int ans = 0;
        int maxf = 0;
        while (j < s.size()) {
            mp[s[j]]++;
            maxf = max(maxf, mp[s[j]]);

            while ((j - i + 1) - maxf > k) {
                mp[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};
