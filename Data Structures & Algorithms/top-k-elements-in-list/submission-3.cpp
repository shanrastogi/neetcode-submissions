class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> mp;
        for(auto it: nums){
            mp[it]++;
        }
        for(auto it: mp){
            if(pq.size() < k){
                pq.push({it.second, it.first});
            }
            else if(pq.size() == k){
                if(pq.top().first < it.second){
                    pq.pop();
                    pq.push({it.second, it.first});
                }
            }
        }
        vector<int> ans;
        while(pq.size() > 0){
            auto x = pq.top();
            pq.pop();
            ans.push_back(x.second);
        }
        return ans;
    }
};
