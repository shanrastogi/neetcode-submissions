class Solution {
   public:
    int area = 0;
    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    area = max(area, solve(grid, i, j));
                }
            }
        }
        return area;
    }

    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = 2;
        int res = 1;
        for (auto it : dir) {
            int ni = i + it.first;
            int nj = j + it.second;
            res += solve(grid, ni, nj);
        }
        return res;
    }
};
