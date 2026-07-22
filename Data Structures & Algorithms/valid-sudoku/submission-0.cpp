class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> colmp;
        unordered_map<int, unordered_set<int>> rowmp;
        unordered_map<string, unordered_set<int>> sqmp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.')
                    continue;
                else {
                    if(colmp[j].find(board[i][j]-'0') != colmp[j].end()){
                        return false;
                    }
                    if(rowmp[i].find(board[i][j]-'0') != rowmp[i].end()){
                        return false;
                    }
                    string key = to_string(i/3)+"-"+to_string(j/3);
                    if(sqmp[key].find(board[i][j]-'0') != sqmp[key].end()){
                        return false;
                    }
                    colmp[j].insert(board[i][j]-'0');
                    rowmp[i].insert(board[i][j]-'0');
                    sqmp[key].insert(board[i][j]-'0');
                }    
            }
        }
        return true;
    }
};
