class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};
    bool valid(int row, int col, int m, int n) {
        if (row >= 0 && col >= 0 && row < m && col < n)
            return true;
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    fresh++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -1;
                }
            }
        }
        while (!q.empty() && fresh > 0) {
            int size = q.size();
            while (size--) {
                auto t = q.front();
                q.pop();
                int row = t.first;
                int col = t.second;
                for (int k = 0; k < 4; k++) {
                    int nrow = row + x[k];
                    int ncol = col + y[k];
                    if (valid(nrow, ncol, m, n) && grid[nrow][ncol] == 1) {
                        q.push({nrow, ncol});
                        grid[nrow][ncol] = -1;
                        fresh--;
                    }
                }
            }
            time++;
        }
        if(fresh >0) return -1;
        return time;
    }
};