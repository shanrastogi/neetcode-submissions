class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 0;
        if(digits[n-1] == 9){
            carry = 1;
            digits[n-1] = 0;
        } else {
            digits[n-1] = digits[n-1] + 1;
        }            
        int i = n-2;    
        while(carry && i>=0)    {
            int total = digits[i] + carry;            
            if(total == 10) {
                digits[i] = 0;
                carry = 1;                
            } else {
                carry = 0;
                digits[i] = digits[i] + 1;
            }
            i--;
        }
        if(carry){
            vector<int> v1 = {1};
            v1.insert(v1.end(), digits.begin(), digits.end());
            return v1;
        }
        return digits;
    }
};
