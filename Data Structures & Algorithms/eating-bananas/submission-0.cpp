class Solution {
   public:
    int maxElement(vector<int>& piles) {
        long long int maxEl = piles[0];
        for (auto it : piles) {
            if (it > maxEl) {
                maxEl = it;
            }
        }
        return maxEl;
    }
    long long int checkHours(vector<int>& piles, int mid) {
        long long int hours = 0;
        for (auto it : piles) {
            hours += ceil((double)it / (double)mid);
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int low = 1;
        long long int high = maxElement(piles);
        long long int ans = high;
        while (low <= high) {
            long long int mid = low + (high - low) / 2;
            if (checkHours(piles, mid) <= h) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};