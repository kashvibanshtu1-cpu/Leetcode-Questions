class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minsum = nums[0];
        int maxsum = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int v1 = nums[i];
            int v2 = minsum + nums[i];
            int v3 = maxsum + nums[i];
            minsum = min(v1, min(v3, v2));
            maxsum = max(v1, max(v2, v3));
            ans = max(ans, max(abs(minsum), maxsum));
        }
        return abs(ans);
    }
};