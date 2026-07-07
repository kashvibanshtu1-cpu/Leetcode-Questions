class Solution {
public:
    bool isenough(vector<int> piles, int gaurd, int mid) {
        long long hour = 0;
        for (int i = 0; i < piles.size(); i++) {
            hour += piles[i] / mid;
            if (piles[i] % mid != 0) {
                hour++;
            }
        }
        if (hour > gaurd) {
            return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int gaurd) {
        int start = 1;
        int end =0;
        int ans = -1;
        for (int i = 0; i < piles.size(); i++) {
            end = max(end, piles[i]);
        }
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (isenough(piles, gaurd, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};