class Solution {
public:
    bool finish(vector<vector<int>>& adj, vector<bool>& vis,
                vector<bool>& path_vis, int node) {
        vis[node] = true;
        path_vis[node] = true;
        for (int i = 0; i < adj[node].size(); i++) {
            int neighbour = adj[node][i];
            if (path_vis[neighbour])
                return false;
            if (!vis[neighbour]) {
                if (!finish(adj, vis, path_vis, neighbour))
                    return false;
            }
        }
        path_vis[node] = false;
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& nums) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < nums.size(); i++) {
            int source = nums[i][1];
            int destination = nums[i][0];
            adj[source].push_back(destination);
        }
        vector<bool> vis(n, false);
        vector<bool> path_vis(n, false);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (!finish(adj, vis, path_vis, i))
                    return false;
            }
        }
        return true;
    }
};