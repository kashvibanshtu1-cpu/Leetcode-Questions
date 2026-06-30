class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int prefix, suffix;
        for (int i = 0; i < nums.size(); i++) {
            if (i < 1) {
                prefix = 0;
            }
            suffix = sum - prefix - nums[i];
            if (suffix == prefix) {
                return i;
            }
            prefix += nums[i];
        }
        return -1;
    }
};