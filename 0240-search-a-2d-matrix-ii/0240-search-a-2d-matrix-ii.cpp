class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        int rno = arr.size();
        int cno= arr[0].size();
        int row = rno - 1;
        int col = 0;
        while (row >= 0 && col < cno) {
            if (arr[row][col] == tar) {
                return true;
            } else if (arr[row][col] > tar) {
                row--;
            } else {
                col++;
            }
        }
        return false;
    }
};