class Solution {
public:
    int maximumSum(vector<int>& nums) {
       int nodel = nums[0];
       int ans = nums[0];
       int onedel = INT_MIN;
       for(int i=1;i<nums.size();i++){
        int predel = nodel ;
        nodel = max(nums[i],nodel+nums[i]);
        if(onedel == INT_MIN){
            onedel = predel;
        }
        onedel = max(onedel+nums[i],predel);
        ans = max(ans,max(onedel,nodel));
       }
       return ans ;
    }
};