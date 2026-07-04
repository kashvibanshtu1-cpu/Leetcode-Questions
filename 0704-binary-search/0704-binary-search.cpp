class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end) {
            int mid = ((end - start) / 2)+start;
            if (nums[mid] == tar)

                return mid;
            else if (nums[mid] > tar) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
};