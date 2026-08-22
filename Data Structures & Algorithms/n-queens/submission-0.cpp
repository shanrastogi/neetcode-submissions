class Solution {
   public:
    bool isSafe(int row, int col, vector<string>& board, int n) {
        int r = row;
        int c = col;
        while (row >= 0 && col >= 0) {
            if (board[row][col] == 'Q') return false;
            row--;
            col--;
        }
        row = r;
        col = c;
        while (col >= 0) {
            if (board[row][col] == 'Q') return false;
            col--;
        }
        row = r;
        col = c;
        while (col >= 0 && row < n) {
            if (board[row][col] == 'Q') return false;
            col--;
            row++;
        }
        return true;
    }
    void solve(vector<string>& board, vector<vector<string>>& ans, int n, int col) {
        if (col == n) {
            ans.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(board, ans, n, col + 1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        string s = "";
        for (int i = 1; i <= n; i++) {
            s += '.';
        }
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        vector<vector<string>> ans;
        solve(board, ans, n, 0);
        return ans;
    }
};