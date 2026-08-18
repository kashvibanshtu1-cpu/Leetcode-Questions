class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    bool valid(int i, int j, int m, int n) {
        if (i >= 0 && i < m && j >= 0 && j < n) {
            return true;
        }
        return false;
    }
    void dfs(vector<vector<char>>& a, vector<vector<bool>>& vis, int m, int n,
             int i, int j) {
        vis[i][j] = true;
        for (int k = 0; k < x.size(); k++) {
            int row = i + x[k];
            int col = j + y[k];
            if (valid(row, col, m, n) && a[row][col] == '1' &&
                vis[row][col] == false) {
                dfs(a, vis, m, n, row, col);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& a) {
        int m = a.size();
        int n = a[0].size();
        int res = 0;
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '1' && vis[i][j] == false) {
                    dfs(a, vis, m, n, i, j);
                    res++;
                }
            }
        }
        return res;
    }
};