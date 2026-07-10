class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            if (st.size() == 0) {
                ans[i] = 0;
                st.push({temperatures[i], i});
            } else {
                while (!st.empty() && st.top().first <= temperatures[i]) {
                    st.pop();
                }
                if (st.size() == 0)
                    ans[i] = 0;
                else
                    ans[i] = st.top().second - i;
                st.push({temperatures[i], i});
            }
        }
        return ans;
    }
};
