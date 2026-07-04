class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int n = nums.size();
        int start = 0;
        int end = n - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == tar) {
                return mid;
            }
            // PART2
            if (nums[mid] > nums[n - 1]) {
                if (nums[mid] < tar) {
                    start = mid+1;
                } else {
                    if (tar >= nums[0]) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
            } // PART1
            else {
                if (nums[mid] > tar) {
                    end = mid - 1;
                }
                if (nums[mid] < tar) {
                    if (tar <= nums[n - 1]) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};