class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxsum = nums[0];
        int ans = nums[0];
        for(int i=1;i<nums.size();i++){
            int v1 = maxsum + nums[i];
            int v2 = nums[i];
            maxsum = max(v1,v2);
            ans = max(ans , maxsum);
        }
        return ans ;
    }
};