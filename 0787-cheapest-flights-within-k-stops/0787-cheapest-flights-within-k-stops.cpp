class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flight, int src, int dst,
                          int k) {
        vector<int> res(n, 1e8);
        vector<int> temp;
        res[src] = 0;
        for (int i = 0; i <= k; i++) {
            temp = res;
            for (int j = 0; j < flight.size(); j++) {
                int source = flight[j][0];
                int des = flight[j][1];
                int weight = flight[j][2];
                if (res[source] != 1e8 && temp[des] > res[source] + weight) {
                    temp[des] = res[source] + weight;
                }
            }
            res = temp;
        }
        if(res[dst]==1e8){
            return -1;
        }
        return res[dst];
    }
};