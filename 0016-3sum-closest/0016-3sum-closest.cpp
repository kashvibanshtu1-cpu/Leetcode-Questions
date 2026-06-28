class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int closesum = nums[0] + nums[1] + nums[2];
        for (int i = 0; i < n - 2; i++) {
            int head = i + 1;
            int tail = n - 1;
            while (head < tail) {
                int sum = nums[i] + nums[head] + nums[tail];
                if (abs(tar - sum) <= abs(tar - closesum)) {
                    closesum = sum;
                }
                if (sum < tar) {
                    head++;
                } else if (sum == tar) {
                    return sum;
                } else {
                    tail--;
                }
            }
        }
        return closesum;
    }
};