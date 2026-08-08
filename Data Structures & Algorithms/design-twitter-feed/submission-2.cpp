class Twitter {
public:
    unordered_map<int, set<int>> followerMap;
    unordered_map<int, vector<pair<int,int>>> tweetsMap;
    long long time;
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it: tweetsMap[userId]){
            pq.push(it);
        }
        for(auto it: followerMap[userId]){
            for(auto it2: tweetsMap[it]){
                pq.push(it2);
            }
        }
        vector<int> ans;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            ans.push_back(it.second);
            if(ans.size()==10)
                break;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId)
            return;
        followerMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followerMap[followerId].erase(followeeId);
    }
};