class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
   vector<int> y = {0, 0, -1, 1};
    bool valid(int row, int col, int m, int n) {
        if (row >= m || col >= n || row < 0 || col < 0) {
            return false;
        }
        return true;
    }

    void countisland(vector<vector<char>>& grid, vector<vector<bool>>& vis,
                     int i, int j, int m, int n) {
        vis[i][j] = true;
        if (i == m || j == n) {
            return;
        }
        for (int k = 0; k < 4; k++) {
            int row = i + x[k];
            int col = j + y[k];
            if (valid(row, col, m, n) && grid[row][col] == '1' &&
                vis[row][col] == false) {
                countisland(grid, vis, row, col, m, n);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && vis[i][j] == false) {
                    countisland(grid, vis, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};