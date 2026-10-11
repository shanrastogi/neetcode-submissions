class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> zeroes;
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == 0) {
                    zeroes.push_back({i, j});
                }
            }
        }
        for (auto it : zeroes) {
            int row = it.first;
            int col = it.second;
            for (int i = 0; i < matrix[0].size(); i++) {
                matrix[row][i] = 0;
            }
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
