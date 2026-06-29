class Solution {
public:
    bool find(vector<int> sarr, vector<int> tarr) {
        for (int i = 0; i < sarr.size(); i++) {
            if (tarr[i] > sarr[i]) {
                return false;
            }
            
        }return true;
    }
    string minWindow(string s, string t) {
        vector<int> tarr(256, 0);
        vector<int> sarr(256, 0);
        for (int i = 0; i < t.size(); i++) {
            tarr[t[i]]++;
        }
        int low = 0;
        int minlen = INT_MAX;
        int start = -1;
        for (int high = 0; high < s.size(); high++) {
            sarr[s[high]]++;
            while (find(sarr, tarr)) {
                int len = high - low + 1;
                if (len < minlen) {
                    minlen = len;
                    start = low;
                }
                sarr[s[low]]--;
                low++;
            }
        }
        if (start == -1)
    return "";
        return s.substr(start, minlen);
    }
};