class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty()) {
                st.push(s[i]);
                continue;
            } else if (abs(st.top()-s[i])==32 ) {
                st.pop();
                continue;
            }
            st.push(s[i]);
        }
        if(st.empty()) return "";
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};