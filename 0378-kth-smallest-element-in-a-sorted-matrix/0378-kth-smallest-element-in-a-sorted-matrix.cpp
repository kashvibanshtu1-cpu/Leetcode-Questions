class Solution {
public:
    int fun(vector<vector<int>>& arr, int guess, int m, int n) {
        int count =0;
        int row = m-1 ;
        int col = 0;
        while(row >=0 && col < n){
            if(arr[row][col]<=guess){
                count += row +1 ;
                col++ ;
            }
            else {
                row--;
            }
        }
        return count ;
    }
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int m = arr.size();
        int n = arr[0].size();
        int start = arr[0][0];
        int end = arr[m - 1][n - 1];
        int ans;
        while (start <= end) {
            int guess = start + (end - start) / 2;
            int count = fun(arr, guess, m, n);
            if (count < k) {
                start = guess + 1;
            } else {
                ans = guess;
                end = guess - 1;
            }
        }
        return ans;
    }
};