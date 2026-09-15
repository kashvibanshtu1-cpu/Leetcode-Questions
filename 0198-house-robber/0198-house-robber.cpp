class Solution {
public:
   map<pair<int,int>,int> dp ;
    int money(vector<int>& nums, int i, int will) {
        if (i >= nums.size()) {
            return 0;
        }
        if(dp.find({i,will})!= dp.end()){
            return dp[{i,will}];
        }

        if (will == 0) {
            dp[{i,will}]= money(nums, i + 1, 1);
        }
        else {
            int rob = nums[i] + money(nums, i + 1, 0);
            int skip = money(nums, i + 1, 1);
            dp[{i,will}] =max(rob, skip);

          }  return dp[{i,will}];
        
    
    }
    int rob(vector<int>& nums) {
        return money(nums, 0, 1);
    }
};