class Solution {
public:
    int minSubArrayLen(int tar, vector<int>& nums) {
        int low =0;
        int minlen = INT_MAX;
        int sum =0;
        for(int high =0;high<nums.size();high++){
            sum += nums[high];
            while(sum>= tar){
                int len = high-low+1;
                minlen = min(minlen , len);
                sum -= nums[low]; 
                low++;
            }
        }
        if(minlen == INT_MAX){
            return 0;
        }
        return minlen ;
    }
};