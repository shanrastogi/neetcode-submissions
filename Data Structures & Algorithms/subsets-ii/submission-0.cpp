class Solution {
   public:
    vector<vector<int>> ans;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        solve(0, {}, nums);
        return ans;
    }
    void solve(int i, vector<int> path, vector<int>& nums) {
        if (i == nums.size()) {
            ans.push_back(path);
            return;
        }
        path.push_back(nums[i]);
        solve(i + 1, path, nums);
        path.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        solve(i + 1, path, nums);
    }
};
