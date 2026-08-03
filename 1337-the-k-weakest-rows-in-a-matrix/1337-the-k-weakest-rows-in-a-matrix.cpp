class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        int count =0;
        vector<int> ans ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(mat[i][j]==1){
                count++;
               }
            }
         pq.push({count,i});
         count =0;
        }
        while(k--){
            int num = pq.top().second ;
            pq.pop();
            ans.push_back(num);
        }
        return ans ;
    }
};