class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < board.size(); i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
            }
            if (board[i][n - 1] == 'O') {
                q.push({i, n - 1});
            }
        }

        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
            }
            if (board[m - 1][i] == 'O') {
                q.push({m - 1, i});
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            board[x][y] = 'A';
            q.pop();
            for (auto it : dir) {
                int dx = x + it.first;
                int dy = y + it.second;
                if (dx >= 0 && dx < m && dy >= 0 && dy < n && board[dx][dy] == 'O') {
                    q.push({dx, dy});
                }
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
