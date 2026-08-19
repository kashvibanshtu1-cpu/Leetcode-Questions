class Solution {
public:
    void dfs(vector<vector<int>>& con, vector<bool>& vis, int node) {
        vis[node] = true;
        for (int j = 0; j < con.size(); j++) {
            if (con[node][j] == 1 && vis[j] == false) {
                dfs(con, vis, j);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& con) {
        int n = con.size();
        vector<bool> vis(n, false);
        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] != true) {
                dfs(con, vis, i);
                provinces++;
            }
        }
        return provinces;
    }
};