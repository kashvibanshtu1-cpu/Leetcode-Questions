class Solution {
public:
    bool valid(int row, int col, int m, int n) {
        if (row >= 0 && col >= 0 && row < m && col < n) {
            return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        res[0][0] = 0;
        pq.push({grid[0][0], {0, 0}}); // weight,row,col
        int x[] = {-1, 1, 0, 0};
        int y[] = {0, 0, -1, 1};
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int weight = t.first;
            int row = t.second.first;
            int col = t.second.second;
            for (int i = 0; i < 4; i++) {
                int nrow = row + x[i];
                int ncol = col + y[i];
                if(valid(nrow, ncol, m, n)){
                int maxw = max(weight, grid[nrow][ncol]);
                if ( maxw < res[nrow][ncol]) {
                    res[nrow][ncol] = maxw;
                    pq.push({maxw,{ nrow, ncol}});
                }
                }
            }
        }
        return res[m - 1][n - 1];
    }
};