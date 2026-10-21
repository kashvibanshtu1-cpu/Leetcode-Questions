class Solution {
public:
    void valid(vector<int>& nums,vector<vector<int>> &ans ,vector<int> &temp ,int i,int n){
       if(i==n){
        ans.push_back(temp);
        return ;
       }
       valid(nums,ans,temp,i+1,n); // skip
       temp.push_back(nums[i]);
       valid(nums,ans,temp,i+1,n); // take 
       temp.pop_back();
       return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans ;
        vector<int> temp ;
        int n = nums.size();
        valid(nums,ans, temp,0,n);
        return ans ;
    }
};