class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size()-1;
        int ans =0;
        int curr =0;
        while(l<r){
            curr = (r-l)*min(heights[l], heights[r]);
            ans = max(ans,curr);
            if(heights[l] <= heights[r]){
                l++;
            } else {
                r--;
            }
        }
        return ans;
    }
};
