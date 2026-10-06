class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxsum=nums[0];
        int sum=nums[0];
        int res=nums[0];
        for(int i=1;i<n;i++){
            int c1=nums[i]; // either start new
            int c2=maxsum+nums[i];   // or continue with the previous answer
            maxsum=max(c1,c2);
            res=max(res,maxsum); 
        }
        return res;
    }
};