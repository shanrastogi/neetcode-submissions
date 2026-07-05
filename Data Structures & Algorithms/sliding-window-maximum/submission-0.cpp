class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i=0;
        int j = 0;
        vector<int> ans;
        deque<int> q;
        while(j < nums.size()){
            while(q.size() > 0 && q.back() < nums[j]){
                q.pop_back();
            }
            q.push_back(nums[j]);
            if(j-i+1 <k){
                j++;
            }
            else if(j-i+1 == k){
                ans.push_back(q.front());
                if(nums[i] == q.front()){
                    q.pop_front();                    
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};
