class Solution {
public:
    bool fun(vector<int>& nums, int k, int guess) {
        int child = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > guess) {
                child++;
                sum = nums[i];
            }
        }
        if (child > k)
            return false;
        return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int start = *min_element(nums.begin(), nums.end());
        int end = 0;
        for (int i = 0; i < nums.size(); i++) {
            end += nums[i];
        }
        int ans = 0;
        while (start <= end) {
            int guess = start + (end - start) / 2;
            if (fun(nums, k, guess)) {
                ans = guess;
                end = guess - 1;
            } else {
                start = guess + 1;
            }
        }
        return ans;
    }
};