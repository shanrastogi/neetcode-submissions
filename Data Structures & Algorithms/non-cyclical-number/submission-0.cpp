class Solution {
   public:
    bool isHappy(int n) {
        int slow = n;
        int fast = solve(n);
        while (slow != fast) {
            fast = solve(fast);
            fast = solve(fast);
            slow = solve(slow);
        }
        return fast == 1;
    }
    int solve(int n) {
        int sum = 0;
        while (n) {
            int x = n % 10;
            sum += x * x;
            n = n / 10;
        }
        return sum;
    }
};
