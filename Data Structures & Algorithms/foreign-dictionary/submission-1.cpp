class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char, vector<char>> adjList;
        string ans = "";
        unordered_map<char, int> indegree;
        queue<char> q;
        for(const string& w : words) for(char c : w) indegree[c] = 0;
        for(int i = 1; i < words.size(); i++){
            string first = words[i-1];
            string second = words[i];
            int j = 0, k = 0;
            bool found = false;
            while(j < first.size() && k < second.size()){
                if(first[j] != second[k]){
                    indegree[second[k]]++;
                    adjList[first[j]].push_back(second[k]);
                    found = true;
                    break;
                }
                j++; k++;
            }
            if (!found && first.size() > second.size()) return "";
        }
        for(auto it: indegree){
            if(it.second == 0){
                q.push(it.first);
            }
        }
        while(!q.empty()){
            char node = q.front();
            q.pop();
            ans += node;
            for(auto it: adjList[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        if(indegree.size() == ans.size())
            return ans;
        return "";    
    }
};