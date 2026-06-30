class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int n= first.size();
        int m = second.size();
        vector<vector<int>> ans ;
        int i=0;
        int j=0;
        while(i<n && j<m){
            int start = max(first[i][0],second[j][0]);
            int end = min(first[i][1],second[j][1]);
            if(start<=end){
                ans.push_back({start,end});
            }
            if (first[i][1]>= second[j][1]){
                j++;
            }
            else {
                i++;
            }
        }
        return ans ;
    }
};