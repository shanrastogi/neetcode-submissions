class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m-1;
        while(high >= low){
            int mid = (low + high)/2;
            if(target <=  matrix[mid][n-1]){
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        if (low >= m) return false; 
        int index =low;
        low = 0;
        high = n-1;
        while(low <= high){
            int mid = (low+high)/2;
            if(target ==  matrix[index][mid])
                return true;
            if(target < matrix[index][mid]){
                 high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return false;
    }
};
