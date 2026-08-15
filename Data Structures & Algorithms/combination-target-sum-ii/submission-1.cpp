class Solution {
   public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        dfs(ans, candidates, target, 0, {});
        return ans;
    }
    void dfs(vector<vector<int>>& ans, vector<int>& candidates, int target, int index,
             vector<int> path) {
        if (target == 0) {
            ans.push_back(path);
            return;
        }
        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target) return;
            path.push_back(candidates[i]);
            dfs(ans, candidates, target - candidates[i], i + 1, path);
            path.pop_back();
        }
    }
};
