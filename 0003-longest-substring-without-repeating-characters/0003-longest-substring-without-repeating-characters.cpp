class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, int> mp;
        int low = 0;
        int n = s.size();
        for (int high = 0; high < n; high++) {
            while (mp.find(s[high]) != mp.end()) {
                mp[s[low]]--;
                if (mp[s[low]] == 0) {
                    mp.erase(s[low]);
                }
                low++;
            }
            mp[s[high]]++;
            int len = high - low + 1;
            ans = max(ans, len);
            
        }
        return ans;
    }
};