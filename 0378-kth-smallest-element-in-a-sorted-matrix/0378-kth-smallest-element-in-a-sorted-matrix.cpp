class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
       priority_queue<int > pq ;
       int m=mat.size();
       int n = mat[0].size(); 
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            pq.push(mat[i][j]);
        }
       }
       while(pq.size() != k){
        pq.pop();
       } 
       return pq.top();
    }
};