class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) sum += it;
        if (sum % 2 == 1) return false;
        int target = sum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, nums, target, dp);
    }

    bool solve(int i, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i == nums.size()) return false;
        if (dp[i][target] != -1) return dp[i][target];
        bool take = false;
        if (nums[i] <= target) take = solve(i + 1, nums, target - nums[i], dp);
        bool notake = solve(i + 1, nums, target, dp);
        return dp[i][target] = take || notake;
    }
};
