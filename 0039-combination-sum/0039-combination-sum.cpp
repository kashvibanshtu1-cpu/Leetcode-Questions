class Solution {
public:
    vector<vector<int>> ans;
    vector<int> diary;
    int target = 0;
    int sum = 0;
    void valid(vector<int>& nums, int indx, int n) {
        if (indx == n) {
            if (sum == target) {
                ans.push_back(diary);
            }
            return;
        }
        // skip the value
        valid(nums, indx + 1, n);
        // add the value
        if (sum + nums[indx] <= target) {
            sum += nums[indx];
            diary.push_back(nums[indx]);
            valid(nums, indx, n);
            diary.pop_back();
            sum -= nums[indx];
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int t) {
        sum = 0;
        target = t;
        ans.clear();
        diary.clear();
        valid(nums, 0, nums.size());
        return ans;
    }
};