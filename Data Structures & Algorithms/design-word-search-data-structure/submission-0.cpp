class TrieNode {
   public:
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {}
};

class WordDictionary {
   private:
    TrieNode* root;

   public:
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->isEndOfWord = true;
    }

    bool search(string word) { return dfs(word, 0, root); }

    bool dfs(string word, int index, TrieNode* root) {
        TrieNode* node = root;
        for (int i = index; i < word.size(); i++) {
            char ch = word[i];
            if (ch == '.') {
                for (auto it : node->children) {
                    if (dfs(word, i + 1, it.second)) {
                        return true;
                    }
                }
                return false;
            } else {
                if (node->children.find(ch) == node->children.end()) {
                    return false;
                }
                node = node->children[ch];
            }
        }
        return node->isEndOfWord;
    }
};
