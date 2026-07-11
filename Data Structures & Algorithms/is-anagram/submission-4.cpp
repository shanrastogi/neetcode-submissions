class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> mp;
        for(auto ch : s){
            mp[ch]++;
        }
        for(auto ch : t){
            if(mp.find(ch) != mp.end()){
                mp[ch]--;
                if(mp[ch] == 0)
                    mp.erase(ch);
            } else {
                return false;
            }
        }
        if(mp.size() > 0)
            return false;
        return true;
    }
};
