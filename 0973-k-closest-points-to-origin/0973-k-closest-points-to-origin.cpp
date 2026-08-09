class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue < pair<int, int>, vector < pair<int, int>>,
            greater<pair<int, int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int d = (1LL *points[i][0] * points[i][0] +1LL* points[i][1] * points[i][1]);
            pq.push({d, i});
        }
        while (k-- && !pq.empty()) {
            int t = pq.top().second;
            pq.pop();
            ans.push_back({points[t][0], points[t][1]});
        }
        return ans;
    }
};