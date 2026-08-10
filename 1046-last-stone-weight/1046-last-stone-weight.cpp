class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for (int i = 0; i < stones.size(); i++) {
            pq.push(stones[i]);
        }
        int large1 = 0, large2 = 0;
        while (pq.size() != 1) {
            if (!pq.empty()) {
                large1 = pq.top();
                pq.pop();
            }
            if (!pq.empty()) {
                large2 = pq.top();
                pq.pop();
            }
            int diff = large1 - large2;
            pq.push(diff);
        }
        return pq.top();
    }
};