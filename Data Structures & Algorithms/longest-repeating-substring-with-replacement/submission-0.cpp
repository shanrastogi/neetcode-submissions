class Solution {
public:
    int characterReplacement(string s, int k) {
        int i=0, j=0, ans=0, max_freq=0;
        vector<int> hash(26,0);
        while(j < s.size()){
            hash[s[j]-'A']++;
            max_freq = max(max_freq, hash[s[j]-'A']);
            if((j-i+1) - max_freq > k){
                hash[s[i]-'A']--;
                max_freq = 0;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
