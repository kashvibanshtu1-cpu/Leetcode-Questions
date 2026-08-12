class Solution {
public:
    int minRefuelStops(int target, int SF, vector<vector<int>>& stations) {
        int distance = 0;
        priority_queue < int> pq;
        int i = 0;
        int count = 0;
        while (SF< target) {
            while (i < stations.size() && stations[i][0] <= SF ) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty())
                return -1;
            auto t = pq.top();
            pq.pop();
            SF += t;
            count++;
        }
        return count;
    }
};