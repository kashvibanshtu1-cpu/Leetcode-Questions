class Solution {
public:
    unordered_map<int, int> dp;

    int fib(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 0) {
            return 0;
        }
        if (dp.find(n) != dp.end()) {
            return dp[n];
        }
        int a = fib(n - 1);
        int b = fib(n - 2);
        dp[n] = a + b;
        return dp[n];
    }
};