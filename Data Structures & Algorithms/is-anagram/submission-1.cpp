class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp;
        if(s.size() != t.size())
            return false;
        for(int i=0;i<s.size();i++){
            mp[s[i]-'a']++;
            mp[t[i]-'a']--;
        }
        for(auto it: mp){
            if(mp[it.first] > 0)
                return false;
        }
        return true;
    }
};
