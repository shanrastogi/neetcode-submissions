class Solution {
   public:
    int rob(vector<int>& nums) {
        vector<int> dp1(nums.size(), -1);
        vector<int> dp2(nums.size(), -1);
        if(nums.size()==1)
            return nums[0];
        return max(solve(nums, nums.size() - 1, 0, dp1), solve(nums, nums.size(), 1, dp2));
    }
    int solve(vector<int>& nums, int n, int i, vector<int>& dp) {
        if (i >= n) {
            return 0;
        }
        if (dp[i] != -1) return dp[i];
        int pick = nums[i] + solve(nums, n, i + 2, dp);
        int notPick = solve(nums, n, i + 1, dp);
        return dp[i] = max(pick, notPick);
    }
};
