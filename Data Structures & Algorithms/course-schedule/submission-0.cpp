class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            seen++;
            for (auto it : adjList[x]) {
                v[it]--;
                if (v[it] == 0) q.push(it);
            }
        }
        return seen == numCourses;
    }
};
