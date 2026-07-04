class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            if(st.empty()){
                st.push(c);
                continue;
            }
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(c);
            } else if ((st.top() == '(' && c == ')') ||
                       (st.top() == '[' && c == ']') ||
                       (st.top() == '{' && c == '}')) {
                st.pop();
            } else {
                return false;
            }
        }
        if(!st.empty()){
            return false ;
        }
        return true;
    }
};