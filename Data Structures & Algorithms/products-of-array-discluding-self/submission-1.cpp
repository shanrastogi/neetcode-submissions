class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pp(n, 1);
        vector<int> sp(n, 1);
        int x = nums[0];
        for (int i = 1; i < n; i++) {
            pp[i] = x;
            x = nums[i] * x;
        }
        x = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            sp[i] = x;
            x = nums[i] * x;
        }
        for (int i = 0; i < n; i++) {
            sp[i] = sp[i] * pp[i];
        }
        return sp;
    }
};
