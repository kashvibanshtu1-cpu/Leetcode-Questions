class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> dist(n) ;
        for(int i=0;i<n;i++){
            int x= points[i][0];
            int y= points[i][1];
            dist[i]=1LL * x * x + 1LL * y * y;
        }
        priority_queue<pair<long long,int> ,vector<pair<long long,int>>,greater<pair<long long,int>>> pq ;
        for(int i=0;i<n;i++){
            pq.push({dist[i],i});
        }
        vector<vector<int>> ans ;
        while(k--){
            if(!pq.empty()){
                int i = pq.top().second;
                pq.pop();
                ans.push_back({points[i][0],points[i][1]});
            }
        }
        return ans ;
    }
};