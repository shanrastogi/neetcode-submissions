class Solution {
   public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (!isalnum(s[i]) && i < s.size()) {
                i++;
            }
            while (!isalnum(s[j]) && j >= 0) {
                j--;
            }
            if (i < j) {
                if (tolower(s[i]) != tolower(s[j])) {
                    return false;
                }
                i++;
                j--;
            }
        }
        return true;
    }
};
