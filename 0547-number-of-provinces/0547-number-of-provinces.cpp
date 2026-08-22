class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<bool>& vis, int node) {
        vis[node] = true;
        for (int k = 0; k < grid[node].size(); k++) {
            if (grid[node][k] == 1 && vis[k] == false) {
                dfs(grid, vis, k);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<bool> vis(m, false);
        int prov = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && vis[i] == false) {
                    dfs(grid, vis, i);
                    prov++;
                }
            }
        }
        return prov;
    }
};