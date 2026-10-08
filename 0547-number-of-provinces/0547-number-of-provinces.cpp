class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& vis, int city) {
        vis[city] = true;
        for (int j = 0; j < isConnected.size(); j++) {
            if (!vis[j] && isConnected[city][j]==1) {
                dfs(isConnected, vis, j);
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int provinces = 0;
        int n = isConnected.size();
        vector<bool> vis (n, false);
        for (int i = 0; i < n; i++) {
            if(!vis[i]){
               dfs(isConnected,vis,i);
               provinces++;
            }
           }
        return provinces ;
    }
};