class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            auto it = ans.back();
            if (it[1] >= intervals[i][0]) {
                it[0] = min(it[0], intervals[i][0]);
                it[1] = max(it[1], intervals[i][1]);
                ans.back() = it;
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
