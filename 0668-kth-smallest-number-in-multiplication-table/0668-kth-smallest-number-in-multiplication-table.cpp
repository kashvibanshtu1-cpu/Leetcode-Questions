class Solution {
public:
    int fun(int m, int n, int guess) {
        int count = 0;
        for (int i = 1; i <= m; i++) {
            count += min(n, guess / i);
        }

        return count;
    }
    int findKthNumber(int m, int n, int k) {
        int start = 1;
        int end = m * n;
        int ans;
        while (start <= end) {
            int guess = start + (end - start) / 2;
            int count = fun(m, n, guess);
            if (count < k) {
                start = guess + 1;
            } else {
                ans = guess;
                end = guess - 1;
            }
        }
        return ans;
    }
};