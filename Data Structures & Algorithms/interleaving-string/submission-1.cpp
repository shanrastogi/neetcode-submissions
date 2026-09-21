class Solution {
   public:
    bool solve(int i, int j, int k, int a, int b, int c, string& s1, string& s2, string& s3, vector<vector<vector<int>>>& dp) {
        if (i == a && j == b && k == c) return true;
        if (k == c) return false;
        if(dp[i][j][k] != -1){
            return dp[i][j][k];
        }
        bool result = false;
        if (s1[i] == s3[k]) {
            result = solve(i + 1, j, k + 1, a, b, c, s1, s2, s3, dp);
        }
        if (result) return dp[i][j][k]= true;
        if (s2[j] == s3[k]) {
            result = solve(i, j + 1, k + 1, a, b, c, s1, s2, s3, dp);
        }
        return dp[i][j][k] = result;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();
        int l = s3.size();
        vector<vector<vector<int>>> dp (101, vector<vector<int>>(101, vector<int>(101, -1)));
        //std::vector<std::vector<std::vector<int>>> vec(3, std::vector<std::vector<int>>(4, std::vector<int>(5, -1)));
        return solve(0, 0, 0, m, n, l, s1, s2, s3,dp);
    }
};
