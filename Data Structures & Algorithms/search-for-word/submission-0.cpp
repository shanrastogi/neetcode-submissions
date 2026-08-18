class Solution {
   public:
    bool exist(vector<vector<char>> board, string word) {
        // Your code goes here
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, m, n, 0)) return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, string word, int x, int y, int m, int n, int index) {
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        if (index == word.size()) return true;
        if (x >= m || x < 0 || y >= n || y < 0 || board[x][y] != word[index]) return false;
        char temp = board[x][y];
        board[x][y] = '#';
        bool found = false;
        for (int i = 0; i < dir.size(); i++) {
            int dx = x + dir[i].first;
            int dy = y + dir[i].second;
            if (dfs(board, word, dx, dy, m, n, index + 1)) {
                found = true;
                break;
            }
        }
        board[x][y] = temp;
        return found;
    }
};
