class Solution {
public:
    bool valid(int row, int col, int m, int n) {
        if (row >= 0 && row < m && col >= 0 && col < n) {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int m = grid.size();
        int n = grid[0].size();
        int min = 0;
        int fresh = 0;
        vector<int> x = {-1, 1, 0, 0};
        vector<int> y = {0, 0, -1, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -1;
                } else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            while (size--) {
                auto t = q.front();
                q.pop();
                int row = t.first;
                int col = t.second;
                for (int i = 0; i < 4; i++) {
                   int nrow = row + x[i];
                   int ncol = col + y[i];
                    if (valid(nrow, ncol, m, n) && grid[nrow][ncol] == 1) {
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = -1;
                        fresh--;
                    }
                }
            }
            min++;
        }
        if (fresh > 0)
            return -1;
        return min;
    }
};