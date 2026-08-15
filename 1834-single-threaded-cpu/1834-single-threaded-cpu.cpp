class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n= tasks.size();
        vector<int> ans ;
        vector<vector<int>> vec;
        for(int i=0;i<n;i++){
           vec.push_back({tasks[i][0],tasks[i][1],i});
        }
        sort(vec.begin(),vec.end());
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int
        ,int>>> pq ;
        long long currtime = vec[0][0];
        int i=0;
        while (i<n || !pq.empty()){
            if (pq.empty()) {
                currtime = max(currtime, (long long)vec[i][0]);
            }
            while(i<n && vec[i][0]<= currtime){
                pq.push({vec[i][1],vec[i][2]});
                i++;
            }
            auto t = pq.top();
            pq.pop();
            currtime += t.first ;
            ans.push_back(t.second);
        }
        return ans ;
    }
};