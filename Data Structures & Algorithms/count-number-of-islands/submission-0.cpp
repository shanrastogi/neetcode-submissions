class Solution {
public:
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0; 
        int m = grid.size();
        int n = grid[0].size();       
        for(int i=0;i<m;i++){
            for(int j =0;j<n;j++){
                if(grid[i][j] == '1'){
                    ans++;
                    dfs(grid, i,j, m, n);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& grid, int i, int j, int m, int n){
        if(i < 0 || j < 0 || i >= m || j >=n || grid[i][j] == '0' || grid[i][j] == '2'){
            return;
        }
        grid[i][j] = '2';
        for(auto it : dir){
            int nr = i + it.first;
            int nc = j + it.second;
            dfs(grid, nr, nc, m,n);
        }
    }
};
