class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ints, vector<int>& newint) {
        vector<vector<int>> res;
        int start = newint[0];
        int end = newint[1];
        bool insert = false;
        for (int i = 0; i < ints.size(); i++) {
            int str = ints[i][0];
            int ed = ints[i][1];
            if (insert == false && start <= str) {
                res.push_back({start, end});
                insert = true;
            }
            res.push_back({str, ed});
        }
        if (insert == false) {
            res.push_back({start, end});
        }
        int start1 = res[0][0];
        int end1 = res[0][1];
        vector<vector<int>> ans;
        for (int i = 1; i < res.size(); i++) {
            int start2 = res[i][0];
            int end2 = res[i][1];
            if (end1 >= start2) {
                end1 = max(end1, end2);
                continue;
            }
            ans.push_back({start1, end1});
            start1 = start2;
            end1 = end2;
        }
        ans.push_back({start1, end1});
        return ans;
    }
};