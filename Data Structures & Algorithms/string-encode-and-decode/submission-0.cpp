class Solution {
public:
    string encode(vector<string>& strs) {
        string ans = "";
        for(auto it: strs){
            string s = it;
            int length = s.size();
            ans += to_string(length) + '#' +s;
        }
        return ans;
    }

    vector<string> decode(string s) {
        int i=0;
        vector<string> ans;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }
            int length = stoi(s.substr(i, j-i));
            string str = s.substr(j+1, length);
            ans.push_back(str);
            i = j+1+length;
        }
        return ans;
    }
};
