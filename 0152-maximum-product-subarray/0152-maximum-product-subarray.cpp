class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res=nums[0];
        int currmax=nums[0];
        int currmin=nums[0];
        for(int i=1;i<n;i++){
            int c1=nums[i];
            int c2=nums[i]*currmax;
            int c3=nums[i]*currmin;

            currmax=max({c1,c2,c3});
            currmin=min({c1,c2,c3});
            res=max({res,currmax,currmin});

        }
        return res;
            }
};