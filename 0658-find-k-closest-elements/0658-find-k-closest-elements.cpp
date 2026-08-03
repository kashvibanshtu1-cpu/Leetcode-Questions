class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        vector<int> ans;
        for (int i = 0; i < arr.size(); i++) {
            int diff = arr[i] - x ;
            if (diff < 0)
                diff = -1 * diff;
            pq.push({diff,arr[i]});
        }
        while (k--) {
            ans.push_back({pq.top().second});
            pq.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};