class Solution {
   public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        for (i = 0; i < intervals.size(); i++) {
            if (newInterval[0] > intervals[i][1]) {
                ans.push_back(intervals[i]);
            } else {
                break;
            }
        }

        int j = 0;
        for (j = i; j < intervals.size(); j++) {
            if(intervals[j][0] <= newInterval[1]){
                newInterval[0] = min(intervals[j][0], newInterval[0]);
                newInterval[1] = max(intervals[j][1], newInterval[1]);
            } else {
                break;
            }
        }
        ans.push_back(newInterval);

        int k = 0;
        for (k = j; k < intervals.size(); k++) {
            ans.push_back(intervals[k]);
        }
        return ans;
    }
};
