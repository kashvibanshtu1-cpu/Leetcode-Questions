class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int ans = nums[0];
       int minP = nums[0];
       int maxP = nums[0];
       for(int i=1;i<nums.size();i++){
        int v1= minP * nums[i];
        int v2 =maxP * nums[i];
        int v3= nums[i];
        minP = min(v1,min(v2,v3));
        maxP = max(v1,max(v2,v3));
        ans = max(minP,max(ans,maxP));
       }
       return ans ; 
    }
};