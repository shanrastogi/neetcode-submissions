class Solution {
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for (auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        queue<vector<int>> q;
        q.push({0, src, 0});
        while (!q.empty()) {
            auto element = q.front();
            q.pop();
            int steps = element[0];
            int node = element[1];
            int currNodePrice = element[2];
            if (steps > k) continue;
            for (auto it : adj[node]) {
                if (currNodePrice + it.second < dist[it.first] && steps <= k) {
                    dist[it.first] = currNodePrice + it.second;
                    q.push({steps + 1, it.first, dist[it.first]});
                }
            }
        }
        if (dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};