class Solution {
public:
    bool fun(vector<int>& candies, long long k,int guess) {
        long long child = 0;
        for (int i = 0; i < candies.size(); i++) {
            if (candies[i] >= guess) {
                child += candies[i] / guess;
            }
        }
        if (child >= k)
            return true;
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int start = 1;
        int end = *max_element(candies.begin(),candies.end());
        long long sum = 0;
        for (int i = 0; i < candies.size(); i++) {
            sum+= candies[i];
        }
        if(sum<k) return 0;
        int ans = 0;
        while (start <= end) {
            int guess = start + (end - start) / 2;
            if (fun(candies, k, guess)) {
                ans = guess;
                start = guess + 1;
            } else {
                end = guess - 1;
            }
        }
        return ans;
    }
};