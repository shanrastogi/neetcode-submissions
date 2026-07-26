class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int min = INT_MAX;
        int ans = 0;
        for (auto it : prices) {
            if (it < min) {
                min = it;
            } else {
                ans = max(ans, it - min);
            }
        }
        return ans;
    }
};
