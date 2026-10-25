class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    bool valid(int i, int j, int m, int n) {
        if (i >= m || j >= n || i < 0 || j < 0) {
            return false;
        }
        return true;
    }
    void fun(vector<vector<int>>& grid, int color, int row, int col,
             vector<vector<bool>>& vis, int orignal_color) {
        vis[row][col] = true;
        if (grid[row][col] == orignal_color) {
            grid[row][col] = color;
            for (int k = 0; k < 4; k++) {
                int nrow = row + x[k];
                int ncol = col + y[k];
                if (valid(nrow, ncol, grid.size(), grid[0].size()) &&
                    !vis[nrow][ncol]) {
                    fun(grid, color, nrow, ncol, vis, orignal_color);
                }
            }
        }
        return;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& grid, int sr, int sc,
                                  int color) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        int orignal_color = grid[sr][sc];
        fun(grid, color, sr, sc, vis, orignal_color);
        return grid;
    }
};