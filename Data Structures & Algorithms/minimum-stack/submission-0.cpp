class MinStack {
   public:
    stack<pair<int, int>> st;
    MinStack() {}

    void push(int val) {
        if (st.empty()) {
            st.push({val, val});
        } else {
            int minValue = st.top().second;
            if (val < minValue) {
                st.push({val, val});
            } else {
                st.push({val, minValue});
            }
        }
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};
