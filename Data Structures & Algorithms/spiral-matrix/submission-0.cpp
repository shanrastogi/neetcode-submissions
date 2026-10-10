class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top = 0;
        int down = matrix.size();
        int left = 0;
        int right = matrix[0].size();
        vector<int> ans;
        while (left < right && top < down) {
            for (int i = left; i < right; i++) {
                ans.push_back(matrix[top][i]);
            }
            top++;
            for (int i = top; i < down; i++) {
                ans.push_back(matrix[i][right - 1]);
            }
            right--;
            if (!(left < right && top < down)) {
                break;
            }
            for (int i = right - 1; i >= left; i--) {
                ans.push_back(matrix[down - 1][i]);
            }
            down--;
            for (int i = down - 1; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        return ans;
    }
};
