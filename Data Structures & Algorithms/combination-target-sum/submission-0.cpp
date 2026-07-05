class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        solve(nums, target, {}, 0);
        return ans;
    }
    void solve(vector<int>& nums, int target, vector<int> path, int index) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        if (target < 0 || index == nums.size()) {
            return;
        }
        path.push_back(nums[index]);
        solve(nums, target - nums[index], path, index);
        path.pop_back();
        solve(nums, target, path, index + 1);
    }
};
