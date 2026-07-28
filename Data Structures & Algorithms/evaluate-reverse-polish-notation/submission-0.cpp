class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for (auto it : tokens) {
            if (it != "+" && it != "-" && it != "*" && it != "/") {
                int x = stoi(it);
                st.push(x);
            } else {
                int x = st.top();
                st.pop();
                int y = st.top();
                st.pop();
                int z = 0;
                if (it == "+") {
                    z = x + y;
                } else if (it == "-") {
                    z = y - x;
                } else if (it == "*") {
                    z = y * x;
                } else if (it == "/") {
                    z = y / x;
                }
                st.push(z);
            }
        }
        return st.top();
    }
};
