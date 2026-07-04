class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int ans = INT_MAX;
        unordered_map<char, int> text_mp;
        for (int i = 0; i < text.size(); i++) {
            text_mp[text[i]]++;
        }
        string b = "balloon";
        unordered_map<char, int> balloon_mp;
        for (int i = 0; i < b.size(); i++) {
            balloon_mp[b[i]]++;
        }
        for (auto p : balloon_mp) {
            char c = p.first;
            int deno = p.second;
            int nums = text_mp[c];
            int times = nums / deno;
            ans = min(ans, times);
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return ans;
    }
};