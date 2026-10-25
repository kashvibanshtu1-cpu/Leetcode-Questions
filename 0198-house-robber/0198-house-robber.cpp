class Solution {
public:
     map<pair<int,int>,int> dp ;
    int fun(vector<int>& nums, int i, int take) {
        if (i >= nums.size()) {
            return 0;
        }
        if(dp.find({i,take})!= dp.end()){
            return dp[{i,take}];
        }
        if (take == 1) {
           int rob = nums[i]+ fun(nums, i + 1, 0); // take
            int skip =fun(nums, i + 1, 1);           // skip
            dp[{i,take}]= max(rob,skip);
        } else {
            dp[{i,take}]= fun(nums, i + 1, 1);
        }
        return dp[{i,take}];
    }
    int rob(vector<int>& nums) {
        return fun(nums, 0, 1);
    
    }
};