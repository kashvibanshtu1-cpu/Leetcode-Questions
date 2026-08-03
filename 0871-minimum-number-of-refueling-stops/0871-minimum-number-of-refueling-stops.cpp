class Solution {
public:
    int minRefuelStops(int target, int startFuel,
                       vector<vector<int>>& stations) {
        int currFuel = startFuel;
        priority_queue<int> pq;
        int i = 0;
        int stop = 0;
        while (currFuel < target) {
            while (i < stations.size() && stations[i][0] <= currFuel) {
                pq.push(stations[i][1]);
                i++;
            }
            if (pq.empty()) {
                return -1;
            }
            int fuel = pq.top();
            pq.pop();
            currFuel += fuel;
            stop++;
        }

        return stop;
    }
};