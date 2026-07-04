class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        int count = 0;
        bool odd = false;
        for (auto p : mp) {
            int freq = p.second;
            if (freq % 2 == 0) {
                count += freq;
            } else {
                odd = true;
                count += freq - 1;
            }
        }
        if (odd == true) {
            return count + 1;
        }
        return count;
    }
};