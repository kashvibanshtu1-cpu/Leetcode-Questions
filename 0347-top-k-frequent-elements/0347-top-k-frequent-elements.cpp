class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }
        priority_queue<pair<int, int>> pq;
        for (auto p : mp) {
            int frequency = p.second;
            int value = p.first;
            pq.push({frequency, value});
        }
        while (k-- && !pq.empty()) {
            auto t = pq.top();
            pq.pop();
            ans.push_back(t.second);
        }
        return ans;
    }
};