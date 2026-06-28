class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        int head = 0;
        int tail = n-1 ;
        int sum =0;
        vector<int> ans ;
        while(head<tail){
            sum= nums[head]+nums[tail];
            if(sum> tar){
                tail--;
            }
            else if(sum== tar){
              ans.push_back(head+1);
              ans.push_back(tail+1); 
              break; 
            }
            else{
                head++;
            }
        }
        return ans ;
    }
};