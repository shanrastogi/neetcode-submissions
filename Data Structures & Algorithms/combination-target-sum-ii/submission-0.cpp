class Solution {
   public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> combo;

        backtrack(candidates, target, 0, combo, result);
        return result;
    }
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& combo,
                   vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(combo);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            if(i > start && candidates[i] == candidates[i-1])
                continue;
            int curr = candidates[i];
            if (candidates[i] > target) {
                return;
            }
            combo.push_back(curr);
            backtrack(candidates, target - curr, i+1, combo, result);
            combo.pop_back();
        }
    }
};
