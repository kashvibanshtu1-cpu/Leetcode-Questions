class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int tar) {
        int rowno = arr.size();
        int colno = arr[0].size();
        // int start = 0;
        // int end = rowno - 1;
        // int row = -1;
        // while (start <= end) {
        //     int mid = start + (end - start) / 2;
        //     if (arr[mid][0] == tar) {
        //         return true;
        //     }
        //     else if (arr[mid][0] > tar) {
        //         end = mid - 1;
        //     } else {
        //         row = mid ;
        //         start = mid + 1;
        //     }
        // }
        // if(row == -1){
        //     return false ;
        // }
        // int star = 0;
        // int ed = colno-1;
        // while (star <= ed) {
        //     int med = star + (ed - star) / 2;
        //     if (arr[row][med] == tar) {
        //         return true;
        //     } else if (arr[row][med] > tar) {
        //         ed = med - 1;
        //     } else {
        //         star = med + 1;
        //     }
        // }
        // return false;
        int start = 0;
        int end = rowno * colno - 1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            int row = mid / colno;
            int col = mid % colno;
            if (arr[row][col] == tar){
                return true;
            }
            else if (arr[row][col] > tar) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return false;
    }
};