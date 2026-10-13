class Solution {
   public:
    vector<int> plusOne(vector<int>& digits) {
        long long num = 0;
        int n = digits.size();
        for (int i = 0; i < n; i++) {
            num = num * 10 + digits[i];
        }
        cout<<num<<endl;
        num = num + 1;
        vector<int> ans;
        while (num > 0) {
            ans.push_back(num % 10);
            num = num / 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
