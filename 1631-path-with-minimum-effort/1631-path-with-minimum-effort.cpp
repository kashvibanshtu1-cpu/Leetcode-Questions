
class Solution {
public:
    vector<int> x = {-1, 1, 0, 0};
    vector<int> y = {0, 0, -1, 1};

    bool fun(int i, int j, int m, int n) {
        if (i >= m || j >= n || j < 0 || i < 0) {
            return false;
        }
        return true;
    }

    int minimumEffortPath(vector<vector<int>>& arr) {
        int m = arr.size();
        int n = arr[0].size();

        vector<vector<int>> cost(m, vector<int>(n, INT_MAX));

        priority_queue<
            vector<int>,
            vector<vector<int>>,
            greater<vector<int>>
        > pq;

        cost[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int currCost = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            pq.pop();

            if (currCost > cost[i][j]) {
                continue;
            }

            if (i == m - 1 && j == n - 1) {
                return currCost;
            }

            for (int k = 0; k < 4; k++) {
                int nrow = i + x[k];
                int ncol = j + y[k];

                if (fun(nrow, ncol, m, n)) {
                    int neighbour = arr[nrow][ncol];

                    int costtt = max(
                        currCost,
                        abs(arr[i][j] - neighbour)
                    );

                    if (costtt < cost[nrow][ncol]) {
                        cost[nrow][ncol] = costtt;
                        pq.push({costtt, nrow, ncol});
                    }
                }
            }
        }

        return 0;
    }
};
