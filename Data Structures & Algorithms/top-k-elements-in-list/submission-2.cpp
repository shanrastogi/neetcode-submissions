class Solution {
private:
    static bool compare(pair<int, int> p1, pair<int, int> p2) {    
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;        
        vector<int> ans;
        for(auto it: nums){
            mp[it]++;
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(auto it: mp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
