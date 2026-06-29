class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low = 0;
        int maxlen = INT_MIN;
        int count = 0;
        for (int high = 0; high < nums.size(); high++) {
            if(nums[high]==0){
                count++;
            }
            while (count > k) {
                if (nums[low] == 0) {
                    count--;
                } 
                 low++;
            }
            int len = high - low + 1;
            maxlen = max(maxlen, len);
        }
        return maxlen;
    }
};