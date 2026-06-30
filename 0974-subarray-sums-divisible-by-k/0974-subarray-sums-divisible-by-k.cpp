class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> mp;
        mp[0]++;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int diff;
            if (sum < 0) {
                int modi = abs(sum) % k;
                diff = (-1 * modi + k) % k;
            } else {
                diff = sum % k;
            }
            if (mp.find(diff) != mp.end()) {
                int freq = mp[diff];
                count += freq;
            }
            mp[diff]++;
        }
        return count;
    }
};