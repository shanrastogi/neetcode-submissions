class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;            
            int l = i+1;
            int r = n-1;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == 0){
                    vector<int> vec;
                    vec.push_back(nums[i]);
                    vec.push_back(nums[l]);
                    vec.push_back(nums[r]);
                    ans.push_back(vec);
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                } else if(sum > 0){
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
