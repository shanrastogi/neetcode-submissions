class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        if(nums.size()==1)
            return nums[0];
        return max(solve(0, nums.size() - 2, nums, dp1), solve(1, nums.size() - 1, nums, dp2));
    }
    int solve(int i, int end, vector<int>& nums, vector<int>& dp) {
        if (i > end) {
            return 0;
        }
        if (dp[i] != -1) {
            return dp[i];
        }
        int pick = nums[i] + solve(i + 2, end, nums, dp);
        int notpick = solve(i + 1, end, nums, dp);
        return dp[i] = max(pick, notpick);
    }
};
