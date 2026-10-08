class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string ans;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            if (!st.empty()) {
                if (st.top() == s[i]) {
                    st.pop();
                    continue;
                }
            }

            st.push(s[i]);
        }
        while (!st.empty()) {
            char t = st.top();
            st.pop();
            ans.push_back(t);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};