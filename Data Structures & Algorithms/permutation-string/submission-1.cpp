class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        if(m>n){
            return false;
        } else {
            int i = 0;
            int j = 0;
            unordered_map<char, int> mp;            
            for(auto it: s1){
                mp[it]++;
            }
            int count =mp.size();
            while(j< n){
                if(mp.find(s2[j]) != mp.end()){
                    mp[s2[j]]--;
                    if(mp[s2[j]] == 0)
                        count--;
                }
                if(j-i+1 < m){
                    j++;
                }
                else if(j-i+1 == m){
                    if(count == 0)
                        return true;
                    if(mp.find(s2[i]) != mp.end()){
                        mp[s2[i]]++;
                        if(mp[s2[i]] == 1)
                            count++;
                    }
                    i++;
                    j++;    
                }
            }
            return false;
        }
    }
};