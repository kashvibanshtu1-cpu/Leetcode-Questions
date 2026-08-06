class Solution {
public:
    void comb(string digits, vector<string>& ans, string diary,
             vector <string>& mp, int i) {
        if (i == digits.size()) {
            ans.push_back(diary);
            return;
        }
        string s = mp[digits[i] - '0'];
        for (int j = 0; j < s.size(); j++) {
            diary.push_back(s[j]);
            comb(digits, ans, diary, mp, i + 1);
            diary.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string diary = "";
        vector<string> mp = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
            };
            comb(digits, ans, diary, mp, 0);
        return ans;
    }
};