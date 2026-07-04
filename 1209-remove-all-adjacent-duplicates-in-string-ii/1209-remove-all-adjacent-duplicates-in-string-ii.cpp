class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        for (int i = 0; i < s.size(); i++) {
            if (st.empty() || s[i] != st.top().first) {
                st.push({s[i], 1});
                continue;
            } else {
                st.top().second++;
                if (st.top().second == k) {
                    st.pop();
                }
            }
        }
        string ans;
        while (!st.empty()) {
            auto p = st.top();
            st.pop();
            while (p.second--) {
                ans.push_back(p.first);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};