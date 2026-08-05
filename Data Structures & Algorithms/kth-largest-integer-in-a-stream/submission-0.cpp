class KthLargest {
   public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int qSize = 0;
    KthLargest(int k, vector<int>& nums) {
        qSize = k;
        for (auto it : nums) {
            pq.push(it);
            if (pq.size() > k) {
                pq.pop();
            }
        }
    }

    int add(int val) {
        pq.push(val);
        if (pq.size() > qSize) {
            pq.pop();
        }
        return pq.top();
    }
};
