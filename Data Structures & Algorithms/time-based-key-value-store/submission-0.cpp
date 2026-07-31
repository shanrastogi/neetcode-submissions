class TimeMap {
   public:
    map<string, map<int, string>> mp;
    TimeMap() {}

    void set(string key, string value, int timestamp) { mp[key][timestamp] = value; }

    string get(string key, int timestamp) {
        string ans = "";
        for (auto it : mp[key]) {
            if (it.first <= timestamp) {
                ans = it.second;
            }
        }
        return ans;
    }
};
