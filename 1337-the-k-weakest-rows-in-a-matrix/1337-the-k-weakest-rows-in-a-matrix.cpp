class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector <int> ans ;
        vector<int> sol(mat.size());
        int count =0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    count ++;
                }
            }
            sol[i] = count ;
            count =0;
        }
        priority_queue<pair<int,int>> pq ;
        for(int i=0;i<sol.size();i++){
            pq.push({sol[i],i});
        }
        while(pq.size() > k){
            pq.pop();
        }
       while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans ;
    }
};