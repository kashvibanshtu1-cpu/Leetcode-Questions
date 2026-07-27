class Solution {
public:
    int findMin(vector<int>& nums) {
       int start = 0 ;
       int end = nums.size() -1 ;
       int ans = INT_MAX ;
       while(start<= end){
        int mid = start+(end-start)/2 ;
        if (nums[mid]<nums[0]){
            // part 1 
            ans = min(ans ,nums[mid]);
            end = mid -1 ;
        }
        else {
            // part 2 
            start= mid+1;
        }
       } 
       if (ans == INT_MAX){
        return nums[0];
       }
       return ans ;
    }
};