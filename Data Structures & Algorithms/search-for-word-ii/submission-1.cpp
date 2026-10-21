class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool endOfWord;

    TrieNode() { endOfWord = false; }
};
class Solution {
   public:
    unordered_set<string> res;
    vector<vector<bool>> visit;
    TrieNode* root;
    Solution() { root = new TrieNode(); }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const string& word : words) {
            addWord(word);
        }

        int ROWS = board.size(), COLS = board[0].size();
        visit.assign(ROWS, vector<bool>(COLS, false));

        for (int r = 0; r < ROWS; ++r) {
            for (int c = 0; c < COLS; ++c) {
                dfs(board, r, c, root, "");
            }
        }
        return vector<string>(res.begin(), res.end());
    }

   private:
    void addWord(const string& word) {
        TrieNode* cur = root;
        for (char c : word) {
            if (!cur->children.count(c)) {
                cur->children[c] = new TrieNode();
            }
            cur = cur->children[c];
        }
        cur->endOfWord = true;
    }
    
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string word) {
        int ROWS = board.size(), COLS = board[0].size();

        if (r < 0 || c < 0 || r >= ROWS || c >= COLS || visit[r][c] ||
            !node->children.count(board[r][c])) {
            return;
        }

        char ch = board[r][c];
        visit[r][c] = true;
        node = node->children[ch];
        word += ch;
        if (node->endOfWord) {
            res.insert(word);
        }

        dfs(board, r + 1, c, node, word);
        dfs(board, r - 1, c, node, word);
        dfs(board, r, c + 1, node, word);
        dfs(board, r, c - 1, node, word);

        visit[r][c] = false;
    }
};