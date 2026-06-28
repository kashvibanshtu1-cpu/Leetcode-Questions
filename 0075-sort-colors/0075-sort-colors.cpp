class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int med =0;
        int high =n-1;
        while(med<=high){
            if(nums[med]==1){
                med++;
            }
            else if(nums[med]==2){
                swap(nums[med],nums[high]);
                high--;
            }
            else {
                swap(nums[med],nums[low]);
                med++;
                low++;
            }
        }
        
    }
};