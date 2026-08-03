class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> choice(n);
        for (int i = 0; i < n; i++) {
            choice[i].first = capital[i];
            choice[i].second = profits[i];
        }
        sort(choice.begin(), choice.end());
        int curr = 0;
        priority_queue<pair<int, int>> pq;
        while (k--) {
            while (curr < n && choice[curr].first <= w) {
                pq.push({choice[curr].second, choice[curr].first});
                curr++;
            }
            if (pq.empty()) {
                break;
            }
            pair<int, int> element = pq.top();
            pq.pop();
            w = w + element.first;
        }
        return w;
    }
};