class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto it : nums) {
            if (s.find(it - 1) == s.end()) {
                int len = 1;
                while (s.find(it + len) != s.end()) {
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};
