class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int onedel = INT_MIN;
        int nodel = arr[0];
        int ans = arr[0];
        for (int i = 1; i < arr.size(); i++) {
            int predel = nodel;
            nodel = max(nodel + arr[i], arr[i]);
            if (onedel == INT_MIN) {
                onedel = predel;
            }
            onedel = max(onedel + arr[i], predel);
            ans = max(ans, max(onedel, nodel));
        }
        return ans;
    }
};