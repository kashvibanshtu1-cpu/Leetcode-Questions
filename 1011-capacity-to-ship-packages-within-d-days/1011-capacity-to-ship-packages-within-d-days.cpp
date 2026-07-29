class Solution {
public:
    bool capacity(vector<int>& w, int k, int guess) {
        int weight = w[0];
        int days = 1;
         for (int i = 1; i < w.size(); i++) {
            weight += w[i];
            if (weight > guess) {
                days++;
                weight = w[i];
            }
        }
        if (days <= k)
            return true;
        return false;
    }
    int shipWithinDays(vector<int>& w, int k) {
        int start = *max_element(w.begin(), w.end());
        int end = 0;
        for (int i = 0; i < w.size(); i++) {
            end += w[i];
        }
        int ans = -1;
        while (start <= end) {
            int guess = start + (end - start) / 2;
            if (capacity(w, k, guess)) {
                ans = guess;
                end = guess - 1;
            } else {
                start = guess + 1;
            }
        }
        return ans;
    }
};