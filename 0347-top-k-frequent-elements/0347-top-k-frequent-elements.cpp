class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue < pair<int, int>,
            vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto i : mp) {
            int number = i.first;
            int frequency = i.second;
            if (k != 0) {
                pq.push({frequency, number});
                k--;
                continue;
            }
            if (frequency <= pq.top().first) {
                continue;
            }
            pq.pop();
            pq.push({frequency, number});
        }
        vector<int> ans;
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};