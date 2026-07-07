class Solution {
public:
    bool canmake(vector<int>& days, int m, int k, int mid) {
        int count = 0;
        int bouquet = 0;
        for (int i = 0; i < days.size(); i++) {
            if (days[i] <= mid) {
                count++;
                if (count == k) {
                    bouquet++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        if (bouquet >= m) {
            return true;
        }
        return false;
    }
    int minDays(vector<int>& days, int m, int k) {
        long long pro = 1LL*m*k;
        if (days.size() < pro) {
            return -1;
        }
        int start = INT_MAX, end = -1;
        int ans = -1;
        for (int i = 0; i < days.size(); i++) {
            start = min(start, days[i]);
            end = max(end, days[i]);
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (canmake(days, m, k, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};