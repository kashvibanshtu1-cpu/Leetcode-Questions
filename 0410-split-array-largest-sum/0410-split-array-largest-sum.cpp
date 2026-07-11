class Solution {
public:
    bool isvalid(vector<int>& nums, int k, long long  mid) {
        int maxsum = 0;
        int part = 1;
        for (int i = 0; i < nums.size(); i++) {
            maxsum += nums[i];
            if (maxsum > mid) {
                maxsum = nums[i];
                part++;
            }
        }
        if (part > k )
            return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        int ans;
        long long  end = sum;
        while (start <= end) {
            long long mid = start + (end-start) / 2;
            if (isvalid(nums, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};