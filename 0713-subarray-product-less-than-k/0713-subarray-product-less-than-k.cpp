class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
         if (k <= 1) return 0;
        int low = 0;
        int count = 0;
        int product = 1;
        for (int high = 0; high < nums.size(); high++) {
            product *= nums[high];
            while (product >= k) {
                product /= nums[low];
                low++;
            }
            count += high - low + 1;
        }
        return count;
    }
};