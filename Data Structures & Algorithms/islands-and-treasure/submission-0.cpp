class Solution {
   public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 0) {
                    bfs(i, j, grid);
                }
            }
        }
    }

    void bfs(int i, int j, vector<vector<int>>& grid) {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<vector<int>> q;
        q.push({i, j, 0});
        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            int curr = q.front()[2];
            q.pop();
            for (auto it : dir) {
                int m = x + it.first;
                int n = y + it.second;
                if (m >= 0 && m < grid.size() && n >= 0 && n < grid[0].size() && grid[m][n] != 0 &&
                    grid[m][n] != -1 && (curr + 1) < grid[m][n]) {
                    grid[m][n] = curr + 1;
                    q.push({m, n, curr + 1});
                }
            }
        }
    }
};
