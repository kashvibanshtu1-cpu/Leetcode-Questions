class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int tar) {
        int n = nums.size();
        int head = 0;
        int tail = n-1 ;
        int sum =0;
        
        while(head<tail){
            sum= nums[head]+nums[tail];
            if(sum> tar){
                tail--;
            }
            else if(sum== tar){
             return {head+1,tail+1};
            }
            else{
                head++;
            }
        }
        return {} ;
    }
};