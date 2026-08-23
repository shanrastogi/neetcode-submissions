class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        queue<vector<int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }
        int ans = 0;
        vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            int x = it[0];
            int y = it[1];
            int time = it[2];
            ans = max(ans, time);
            for (auto d : dir) {
                int dx = x + d.first;
                int dy = y + d.second;
                if (dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size() &&
                    grid[dx][dy] == 1) {
                    grid[dx][dy] = 2;
                    fresh--;
                    q.push({dx, dy, time + 1});
                }
            }
        }
        if (fresh == 0) return ans;
        return -1;
    }
};
