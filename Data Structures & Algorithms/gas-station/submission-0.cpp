class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i = 0;
        int j = cost.size() - 1;
        int tank = gas[j] - cost[j];
        while (i < j) {
            if (tank < 0) {
                j--;
                tank += gas[j] - cost[j];
            } else {
                tank += gas[i] - cost[i];
                i++;
            }
        }
        return tank >= 0 ? j : -1;
    }
};
