class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        set<pair<int, int>> st;
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        vector<int> distance(n + 1, 1e9);
        distance[k] = 0;
        st.insert({0, k});
        while (!st.empty()) {
            auto it = *(st.begin());
            int dist = it.first;
            int node = it.second;
            st.erase({dist, node});
            for (auto x : adj[node]) {
                int adjNode = x.first;
                int edgW = x.second;
                if (edgW + dist < distance[adjNode]) {
                    if (distance[adjNode] != 1e9) st.erase({edgW, adjNode});
                    distance[adjNode] = edgW + dist;
                    st.insert({distance[adjNode], adjNode});
                }
            }
        }
        int ans = -1;
        for (int i = 1; i <= n; i++) {
            if (distance[i] == 1e9) return -1;
            if (distance[i] > ans) ans = distance[i];
        }
        return ans;
    }
};
