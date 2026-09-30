class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int v, int src) {
        vector<int> res(v, INT_MAX);
        vector<vector<pair<int, int>>> adj(v);
        for (int i = 0; i < times.size(); i++) {
            int source = times[i][0];
            int destination = times[i][1];
            int w = times[i][2];
            adj[source - 1].push_back({destination - 1, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        // distance ,node
        src--;
        pq.push({0, src});
        res[src] = 0;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int node = t.second;
            int dist = t.first;
            if (dist > res[node]) {
                continue;
            }
            for (int i = 0; i < adj[node].size(); i++) {
                auto n = adj[node][i];
                int weight = n.second;
                int neigh = n.first;
                if (weight + dist < res[neigh]) {
                    res[neigh] = weight + dist;
                    pq.push({weight + dist, neigh});
                }
            }
        }
        int ans = *max_element(res.begin(), res.end());
        if (ans == INT_MAX) {
            return -1;
        }
        return ans;
    }
};