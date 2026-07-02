class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;
        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;
        }
        for (int i = 0; i < s.size(); i++) {
            int freq = mp[s[i]];
            if (freq == 1) {
                return i;
            }
        }
        return -1;

        // unordered_map<char, pair<int, int>> mp; //<string : freq,indx>
        // for (int i = 0; i < s.size(); i++) {
        //     if (mp.find(s[i]) != mp.end()) {
        //         mp[s[i]].first++;
        //     } else {
        //         mp[s[i]] = {1, i};
        //     }
        // }
        // int ans = INT_MAX;
        // for (auto p : mp) {
        //     if (p.second.first == 1) {
        //         ans = min(ans, p.second.second);
        //     }
        // }
        // if (ans == INT_MAX)
        //     return -1;

        // return ans;
    }
};