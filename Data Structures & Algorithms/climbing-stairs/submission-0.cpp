class Solution {
public:
    int climbStairs(int n) {
        int prev = 0;
        int curr = 1;
        for(int i=1;i<=n+1;i++){
            int total = prev + curr;
            prev = curr;
            curr = total;
        }
        return prev;
    }
};
