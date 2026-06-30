class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
        int i=0;
        int j=0;
        vector<vector<int>> ans ;
        int end1,start1,start2,end2;
        while(i<first.size()&& j<second.size()){
            if(first[i][0]<second[j][0]){
                 start1=first[i][0];
                 end1= first[i][1];
                 start2 = second[j][0];
                 end2 = second[j][1];
            }
            else if(first[i][0]>=second[j][0]){
                 start1=second[j][0];
                 end1=second[j][1];
                 start2 = first[i][0];
                 end2 =  first[i][1];
            }
            if(end1>= start2){
                start1 = max(start1,start2);
                end1=min(end1,end2);
                ans.push_back({start1,end1});
            }
            
            if(first[i][1]<second[j][1]){
                i++;
            }
            else {
                j++;
            }
        }
        return ans ;
    }
};