class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        int count = 0;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        bool odd = false;
        for (auto i : mp) {
            int freq = i.second;
            if (freq % 2 == 0) {
                count += freq;
            } else {
                odd = true;
            }
        }
        if (odd == false) {
            return count;
        }
        if (odd == true) {
            for (auto i : mp) {
                int val = i.second;
                if (val % 2 != 0) {
                    int freq = val - 1;
                    count += freq;
                }
            }
        }
        return count + 1;
    }
};