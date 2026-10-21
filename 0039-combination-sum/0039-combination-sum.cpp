class Solution {
public:
    void valid(vector<int>& cand, int tar, int sum, vector<vector<int>>& ans,
               vector<int>& temp, int i, int n) {
        if (i == n) {
            if (sum == tar) {
                ans.push_back(temp);
            }
            return;
        }
        valid(cand, tar, sum, ans, temp, i + 1, n);
        if (sum + cand[i] <= tar) {
            sum += cand[i];
            temp.push_back(cand[i]);
            valid(cand, tar, sum, ans, temp, i, n);
            temp.pop_back();
            sum -= cand[i];
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int tar) {
        int n = cand.size();
        int sum = 0;
        vector<vector<int>> ans;
        vector<int> temp;
        valid(cand, tar, sum, ans, temp, 0, n);
        return ans;
    }
};