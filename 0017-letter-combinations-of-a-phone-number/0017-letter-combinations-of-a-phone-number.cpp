class Solution {
public:
    void comb(string s, vector<string>& ans, int n, vector<string>& mp,
              string temp, int indx) {
        if (indx == n) {
            ans.push_back(temp);
            return;
        }
        string a = mp[s[indx] - '0'];
        for (int i = 0; i < a.size(); i++) {
            temp.push_back(a[i]);
            comb(s, ans, n, mp, temp, indx+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string s) {
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
            "wxyz"  // 0
        };
         int n = s.size();
        vector<string> ans;
        string temp = "";
        comb(s, ans, n, mp, temp, 0);
        return ans;
    }
};