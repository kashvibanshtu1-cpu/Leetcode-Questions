class Solution {
public:
    bool willbloom(vector<int>& bloom, int guess, int m, int k) {
        int count =0;
        int bouquet =0;
        for (int i = 0; i < bloom.size(); i++) {
            if (bloom[i] <= guess) {
                count++;
                if (count% k == 0) {
                   bouquet++;
                }
            }
            else{
                count =0;
            }
        }
        if (bouquet >=m)
            return true;
        return false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int start = *min_element(bloom.begin(), bloom.end());
        int end = *max_element(bloom.begin(), bloom.end());
        int ans = INT_MAX;
        while (start <= end) {
            int guess = start + (end - start) / 2;
            if (willbloom(bloom, guess, m, k)) {
                ans = min(ans, guess);
                end = guess - 1;
            } else {
                start = guess + 1;
            }
        }
        if(ans == INT_MAX ){
            return -1 ;
        }
        return ans;
    }
};