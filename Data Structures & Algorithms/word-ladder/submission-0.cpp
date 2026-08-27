class Solution {
   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (words.find(endWord) == words.end() || beginWord == endWord) return 0;
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        words.erase(beginWord);
        while (!q.empty()) {
            string node = q.front().first;
            int res = q.front().second;
            q.pop();
            if (node == endWord) return res;
            for (int j = 0; j < node.length(); j++) {
                char original = node[j];
                for (char c = 'a'; c <= 'z'; c++) {
                    node[j] = c;
                    if (words.find(node) != words.end()) {
                        q.push({node, res + 1});
                        words.erase(node);
                    }
                }
                node[j] = original;
            }
        }
        return 0;
    }
};