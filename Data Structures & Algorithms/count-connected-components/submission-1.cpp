class Solution {
   public:
    int ans = 0;
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        for (auto it : edges) {
            adjList[it[0]].push_back(it[1]);
            adjList[it[1]].push_back(it[0]);
        }

        unordered_set<int> vis;
        for (int i = 0; i < n; i++) {
            if (vis.find(i) == vis.end()) {
                ans++;
                dfs(i, vis, adjList);
            }
        }
        return ans;
    }

    void dfs(int node, unordered_set<int>& vis, vector<vector<int>> adjList) {
        vis.insert(node);
        for (auto it : adjList[node]) {
            if (vis.find(it) == vis.end()) dfs(it, vis, adjList);
        }
    }
};
