class Solution {
public:
    int solve(int i, vector<int>& nums, int target, int sum, map<pair<int, int>, int>& mp){
        if(i == nums.size()){
            if(sum == target)
                return 1;
            return 0;    
        }
        if(mp.find({i, sum}) != mp.end()){
            return mp[{i, sum}];
        }
        int pos = solve(i+1, nums, target, sum + nums[i], mp);
        int neg = solve(i+1, nums, target, sum - nums[i], mp);
        return mp[{i, sum}] = pos + neg;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int, int>, int> mp;
        int n = nums.size();
        return solve(0, nums, target, 0, mp);
    }
};
