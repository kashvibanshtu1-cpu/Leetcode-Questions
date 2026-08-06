class Solution {
public:
    void valid(int n, vector<string>& ans, string diary, int open, int close) {
        if (open == n && close == n) {
            ans.push_back(diary);
            return;
        }
        // add (
        if (open < n) {
            diary.push_back('(');
            valid(n, ans, diary, open + 1, close);
            diary.pop_back();
        }
        // add )
        if (close < open) {
            diary.push_back(')');
            valid(n, ans, diary, open, close + 1);
            diary.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string diary = "";
        valid(n, ans, diary, 0, 0);
        return ans;
    }
};