class Solution {
   public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // Your code goes here
        vector<int> v(numCourses, 0);
        vector<vector<int>> adjList(numCourses, vector<int>());
        for (auto it : prerequisites) {
            v[it[0]]++;
            adjList[it[1]].push_back(it[0]);
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (v[i] == 0) q.push(i);
        }
        int seen = 0;
        vector<int> ans;
        while (!q.empty()) {
            int x = q.front();
            ans.push_back(x);
            q.pop();
            seen++;
            for (auto it : adjList[x]) {
                v[it]--;
                if (v[it] == 0) q.push(it);
            }
        }
        if (seen != numCourses) {
            ans = {};
        }
        return ans;
    }
};
