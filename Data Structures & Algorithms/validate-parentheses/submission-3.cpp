class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto it: s){
            if(it == '[' || it == '{' || it == '('){
                st.push(it);
            } else if(st.size() > 0){
                char topElement = st.top();
                if(it == ']' && topElement == '['){
                    st.pop();
                } else if(it == '}' && topElement == '{') {
                    st.pop();
                } else if(it == ')' && topElement == '(') {
                    st.pop();
                } else {
                    return false;
                }
            } else if(st.size() == 0 && it == ']' || it == '}' || it == ')'){
                return false;
            }
        }
        if(st.size() == 0)
            return true;
        return false;    
    }
};
