class Solution {
public:
    bool isindex(vector<int>& cit, int guess) {
        int c = 0;
        for (int i = 0; i < cit.size(); i++) {
            if (cit[i] >= guess) {
                c++;
            }
        }
        if (c >= guess)
            return true;
        return false;
    }
    int hIndex(vector<int>& cit) {
        int start = 0;
        int end = *max_element(cit.begin(), cit.end());
        int ans = -1;
        while (start <= end) {
            int guess = start + (end - start) / 2;
            if (isindex(cit, guess)) {
                ans = guess;
                start = guess + 1;
            } else {
                end = guess - 1;
            }
        }
        return ans;
    }
};