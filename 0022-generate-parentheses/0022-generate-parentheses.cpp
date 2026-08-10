class Solution {
public:
    void gen(vector<string>& ans, string temp, int n, int open, int close) {
        if (open == n && close == n) {
            ans.push_back(temp);
            return;
        }
        if (open < n) {
            temp.push_back('(');
            gen(ans, temp, n, open + 1, close);
            temp.pop_back();
        }
        if (close < open && close < n) {
            temp.push_back(')');
            gen(ans, temp, n, open, close + 1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp = "";
        gen(ans, temp, n, 0, 0);
        return ans;
    }
};