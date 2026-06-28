class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int count =1;
        int head =0;

        for(int tail=1;tail<n;tail++){
            if(nums[tail] == nums[tail-1]){
                count++;
            }
            else {
                count =1;
            }
            if(count <=2){
                head++;
                nums[head] = nums[tail];
              }
        }
        return head+1;
    }
};