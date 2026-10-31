class Solution {
public:
    bool canPartition(vector<int>& arr) {
      int sum = 0 ;
		int n = arr.size();
		for (int i = 0; i<n ; i++) {
			sum += arr[i];
		}
		if (sum%2 != 0)
			return false ;
		int tar = sum/2 ;
		vector<vector<bool>> dp(n + 1, vector<bool>(tar + 1));
		for (int i = 0; i<n + 1; i++) {
			for (int j = 0; j<tar + 1; j++) {
				if (j == 0) {
					dp[i][j] = true ;
					continue ;
				}
				else if (i == 0 && j>0) {
					dp[i][j] = false ;
					continue ;
				}
				
				if (arr[i - 1]> j) {
					dp[i][j] = dp[i - 1][j];
				} else {
					dp[i][j] = dp[i - 1][j - arr[i-1]] || dp[i - 1][j];
				}
				
			}
			
		}
		return dp[n][tar];  
    }
};