class Solution {
public:
    int count(vector<vector<int>>& mat, int mid, int m, int n) {
        int row = m - 1;
        int col = 0;
        int count = 0;
        while (row >= 0 && col < n) {
            int element = mat[row][col];
            if (element <= mid) {
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
        int ans = INT_MAX;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int c = count(mat, mid,m,n);
            if (c >= k) {
                ans = min(mid, ans);
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
};