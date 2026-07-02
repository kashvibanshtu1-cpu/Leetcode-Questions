class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> mp;
        for (int i = 0; i < text.size(); i++) {
            mp[text[i]]++;
        }
        string b = "balloon";
        unordered_map<char, int> bmp;
        for (int i = 0; i < b.size(); i++) {
            bmp[b[i]]++;
        }
        int ans = INT_MAX;
        for (auto p : bmp) {
            char c = p.first;
            int deno = p.second;
            int num = mp[c];
            int times = num/deno;
            ans = min(ans, times);
        }
        return ans;
    }
};