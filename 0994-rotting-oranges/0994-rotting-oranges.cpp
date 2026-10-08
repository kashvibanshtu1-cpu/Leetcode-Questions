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
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int count = 0;
        int fresh = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    grid[i][j] = -1;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if (fresh == 0)
            return 0;
        while (!q.empty()) {
            int s = q.size();
            while (s--) {
                auto t = q.front();
                int i = t.first;
                int j = t.second;
                q.pop();
                for (int k = 0; k < 4; k++) {
                    int row = i + x[k];
                    int col = j + y[k];
                    if (valid(row, col, m, n) && grid[row][col] == 1) {
                        grid[row][col] = -1;
                        q.push({row, col});
                        fresh--;
                    }
                }
            }
            count++;
        }
        if (fresh > 0)
            return -1;

        return count - 1;
    }
};