class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        st.push(s[0]);
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            if (st.empty()) {
                st.push(c);
                continue;
            }
            if (st.top() == c) {
                st.pop();
                continue;
            }
            st.push(c);
        }
        int n = st.size();
        string ans (n, ' ');
        int i = n - 1;
        while (!st.empty()) {
            ans[i] = st.top();
            st.pop();
            i--;
        }
        return ans;
    }
};