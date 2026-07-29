class Solution {
public:
    int fun(vector<vector<int>>& mat, int mid, int m, int n) {
        int row = m - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < n) {
            if (mat[row][col] <= mid) {
                count += row + 1;
                col++;
            } else {
                row--;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int start = mat[0][0];
        int end = mat[m - 1][n - 1];
        int ans = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int count = fun(mat, mid, m, n);
            if (count < k) {
                start = mid + 1;
            } else {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};