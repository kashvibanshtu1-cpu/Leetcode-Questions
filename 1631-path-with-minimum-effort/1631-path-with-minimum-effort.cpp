class Solution {
public:
    bool valid(int row, int col, int m, int n) {
        if (row >= 0 && col >= 0 && row < m && col < n) {
            return true;
        }
        return false;
    }
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        // dist,row,col
        pq.push({0, {0, 0}});
        res[0][0] = 0;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int dist = t.first;
            int row = t.second.first;
            int col = t.second.second;
            if (dist > res[row][col]) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int r = row + x[i];
                int c = col + y[i];
                if (!valid(r, c, m, n)) {
                    continue;
                }
                int diff = abs(heights[row][col] - heights[r][c]);
                int weight = max(diff, dist);
                if (weight < res[r][c]) {
                    res[r][c] = weight;
                    pq.push({weight, {r, c}});
                }
            }
        }
        return res[m - 1][n - 1];
    }
};