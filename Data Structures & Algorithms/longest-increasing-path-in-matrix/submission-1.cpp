class Solution {
   public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int solve(int i, int j, vector<vector<int>>& matrix, int rows, int cols, int preVal,
              vector<vector<int>>& dp) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || matrix[i][j] <= preVal) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int res = 0;
        for (auto d : dir) {
            int nr = i + d.first;
            int nc = j + d.second;
            res = max(res, 1 + solve(nr, nc, matrix, rows, cols, matrix[i][j], dp));
        }
        return dp[i][j] = res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = 0;
        vector<vector<int>> dp(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans = max(ans, solve(i, j, matrix, rows, cols, INT_MIN, dp));
            }
        }
        return ans;
    }
};
