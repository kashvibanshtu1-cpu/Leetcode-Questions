class Solution {
public:
    bool candivide(const vector<int>& candies, long long k, int mid) {
        long long child = 0;
        for (int i = 0; i < candies.size(); i++) {
           child += candies[i]/mid;
        }
        if (child >= k)
            return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for (int i = 0; i < candies.size(); i++) {
            sum = sum + candies[i];
        }
        if (sum < k)
            return 0;
        int start = 1;
        int end = *max_element(candies.begin(), candies.end());
        int ans;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (candivide(candies, k, mid)) {
                ans = mid;
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        return ans;
    }
};