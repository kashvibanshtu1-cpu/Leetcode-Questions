class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    int n= nums.size();
    int frequency = 1;
    int high = 1; 
    int low = 0;
      
    while (high<n){
        if (nums[high]!=nums[high-1]){
            low++;
            nums[low]= nums[high];
            high++;
            frequency++;
        }
        else {
            high++;
        }
    }
    return frequency ;

    }
};