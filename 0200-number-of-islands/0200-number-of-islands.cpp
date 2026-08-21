class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    bool valid(int row, int col, int m, int n) {
        if (row >= 0 && col >= 0 && row < m && col < n)
            return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row,  int col, int m, int n) {
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            int nrow = row + x[i];
            int ncol = col + y[i];
            if (valid(nrow, ncol, m, n) && !visited[nrow][ncol] &&
                grid[nrow][ncol] == '1') {
                dfs(grid, visited, nrow, ncol, m, n);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1' && visited[i][j] == false) {
                    dfs(grid, visited, i, j, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};