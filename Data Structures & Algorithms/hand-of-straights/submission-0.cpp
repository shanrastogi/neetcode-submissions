class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        unordered_map<int, int> mp;
        for (auto it : hand) {
            mp[it]++;
        }
        for (int num : hand) {
            int start = num;
            while (mp[start - 1] > 0) start--;
            while (start <= num) {
                while (mp[start] > 0) {
                    for (int i = start; i < start + groupSize; i++) {
                        if (mp[i] == 0) return false;
                        mp[i]--;
                    }
                }
                start++;
            }
        }
        return true;
    }
};
