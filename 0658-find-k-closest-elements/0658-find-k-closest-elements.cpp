class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ans;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < arr.size(); i++) {
            int d = arr[i] - x;
            if (d < 0)
                d = -1 * d;
            pq.push({d, i});
        }
        while (k-- && !pq.empty()) {
            int t = pq.top().second;
            pq.pop();
            ans.push_back(arr[t]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};