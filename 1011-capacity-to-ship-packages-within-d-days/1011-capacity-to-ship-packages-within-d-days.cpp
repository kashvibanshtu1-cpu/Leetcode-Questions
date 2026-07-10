class Solution {
public:
    bool isvalid(vector<int>& weight, int k, int mid) {
        int days = 1;
        int sum = weight[0];
        for (int i = 1; i < weight.size(); i++) {
            sum += weight[i];
            if (sum > mid) {
                days++;
                sum = weight[i];
            }
        }
        
        if (days > k)
            return false;
        return true;
    }
    int shipWithinDays(vector<int>& weight, int k) {
        int start = *max_element(weight.begin(), weight.end());
        int sum = 0;
        for (int i = 0; i < weight.size(); i++) {
            sum += weight[i];
        }
        int end = sum;
        int ans = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isvalid(weight, k, mid)) {
                ans = min(ans, mid);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};