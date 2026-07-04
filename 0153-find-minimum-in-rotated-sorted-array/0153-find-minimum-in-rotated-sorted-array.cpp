class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int n =nums.size();
        int end = n - 1;
        int ans = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] > nums[n-1]) {
                start = mid + 1;
            } else {
                ans = min(ans, mid);
                end = mid - 1;
            }
        }
        if (ans == INT_MAX) {
            return 0;
        }
        return nums[ans];
    }
};