class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         unordered_map<string, vector<string>> mp;
        vector<vector<string>> ans;
        for(auto s: strs){
            string key(26,'0');
            for(auto c: s){
                key[c-'a']++;
            }
            mp[key].push_back(s);
        }
        for(auto it: mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};
