class Solution {
   public:
    int climbStairs(int n) {
        int f = 0;
        int s = 1;
        for (int i = 1; i <= n; i++) {
            int t = f + s;
            f = s;
            s = t;
        }
        return s;
    }
};
