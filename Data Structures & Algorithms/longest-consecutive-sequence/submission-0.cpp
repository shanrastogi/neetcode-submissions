class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uniqueSet(nums.begin(),nums.end());
        int ans =0;
        for(auto it: uniqueSet){
            if(uniqueSet.find(it-1)  == uniqueSet.end()){
                int currentLength = 1;
                while(uniqueSet.find(it+currentLength)  != uniqueSet.end())
                    currentLength++;
                ans = max(ans,currentLength);    
            }
        }
        return ans;
    }
};
