class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        vector<vector<int>> option;
        for (int i = 0; i < profits.size(); i++) {
            option.push_back({capital[i], profits[i]});
        }
        sort(option.begin(), option.end());
        priority_queue<int> pq;
        int i = 0;
        while (k--) {
            while (i < option.size() && option[i][0] <= w) {
                pq.push(option[i][1]);
                i++;
            }
            if (pq.empty())
                break;
            auto t = pq.top();
            pq.pop();
            w += t;
        }
        return w;
    }
};