/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
      map<int, int> mp;
      for(auto it: intervals)  {
        mp[it.start]++;
        mp[it.end]--;
      }
      int prev = 0;
      int ans = 0;      
      for(auto it: mp){
        prev += it.second;
        ans = max(ans, prev);
      }
      return ans;
    }
};
