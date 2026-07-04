class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (mid > 0 && mid < nums.size() - 1 &&
                nums[mid] > nums[mid - 1] &&
                nums[mid] > nums[mid + 1]) {
                return mid;
            }
            else if (mid < nums.size() - 1 && nums[mid] < nums[mid + 1]) {
                // Ascending slope
                start = mid + 1;
            }
            else {
                // Descending slope
                end = mid - 1;
            }
        }

        return -1;
    }
};