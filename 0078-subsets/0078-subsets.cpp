class Solution {
public:
    void valid(vector<int>& nums, vector<vector<int>>& ans, vector<int>& temp,
               int indx, int n) {
        if (indx == n) {
            ans.push_back(temp);
            return;
        }
        valid(nums, ans, temp, indx + 1, n); // SKIP
        temp.push_back(nums[indx]);
        valid(nums, ans, temp, indx + 1, n); // PICK
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        valid(nums, ans, temp, 0, n);
        return ans;
    }
};