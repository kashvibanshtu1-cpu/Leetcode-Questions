class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int start = 0;
        int n = nums.size();
        int end = n - 1;
        int first = nums[0];
        int last = nums[n - 1];
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == tar) {
                return mid;
            }
            // PART 1
            if (nums[mid] < first) {
                if (nums[mid] > tar) {
                    end = mid - 1;
                } else {
                    if (tar <= last) {
                        start = mid + 1;
                    } else {
                        end = mid - 1;
                    }
                }
            }
            // Part 2
            else {
                if (tar > nums[mid]) {
                    start = mid + 1;
                } else {
                    if (tar >= first) {
                        end = mid - 1;
                    } else {
                        start = mid + 1;
                    }
                }
            }
        }
        return -1;
    }
};