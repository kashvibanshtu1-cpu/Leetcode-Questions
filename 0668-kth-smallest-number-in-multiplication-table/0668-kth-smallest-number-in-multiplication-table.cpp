class Solution {
public:
    int fun(int m, int n, int mid) {
        int count =0;
        for (int i = 1; i <= m; i++) {
            count += min(n, mid / i);
        }
        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int start = 1;
        int end = m * n;
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int count = fun(m, n, mid);
            if (count < k) {
                start = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};