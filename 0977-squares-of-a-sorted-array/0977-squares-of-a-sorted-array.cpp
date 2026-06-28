class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] *=nums[i];
        }
        int head=0;
        int tail=n-1;
        vector<int> ans ;
        while(head<=tail){
            if(nums[head]<=nums[tail]){
               ans.push_back(nums[tail]);
               tail--;
            }
            else {
                ans.push_back(nums[head]);
                head++;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans ;
    }
};