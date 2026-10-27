class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (m > n)
            return {};
        unordered_map<char, int> mp_p;
        unordered_map<char, int> mp_s;
        for (int i = 0; i < m; i++) {
            mp_p[p[i]]++;
        }
        int low = 0;
        vector<int> ans;
        for (int high = 0; high < n; high++) {
            mp_s[s[high]]++;
            int len = high - low + 1;
            if (len < m)
                continue;
            if (len > m) {
                mp_s[s[low]]--;
                if (mp_s[s[low]] == 0) {
                    mp_s.erase(s[low]);
                }
                low++;
            }
            if (high - low + 1 == m && mp_p == mp_s) {
                ans.push_back(low);
            }
        }
        return ans;
    }
};