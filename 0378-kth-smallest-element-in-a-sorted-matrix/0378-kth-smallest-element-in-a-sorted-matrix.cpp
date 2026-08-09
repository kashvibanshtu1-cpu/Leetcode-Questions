class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
      	priority_queue<pair<pair<int, int>,int>, vector<pair<pair<int, int>,int>>, greater<pair<pair<int, int>,int>> > pq ;
		int m = mat.size();
		int n = mat[0].size();
		for (int i = 0; i<m; i++) {
			pq.push({{mat[i][0], i}, 0}); // element,row,col
		}
		vector<int> ans ;
		int row = 0;
		int col = 0;
		while (!pq.empty()) {
			auto t = pq.top();
			pq.pop();
			ans.push_back(t.first.first);
			int row = t.first.second;
			int col = t.second + 1;
			if (row <m && col<n) {
				pq.push({{mat[row][col], row}, col});
			}
		}
		return ans[k-1] ;  
    }
};